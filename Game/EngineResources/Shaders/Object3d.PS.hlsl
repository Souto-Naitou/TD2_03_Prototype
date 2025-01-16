#include "object3d.hlsli"

struct Camera
{
    float3 worldPosition;
};

struct Material
{
    float4 color;
    float4x4 uvTransform;
    float shininess;
};

struct Lighting
{
    int enableLighting;
    int lightingType;
};

struct PointLight
{
    int enablePointLight; //!< ポイントライトを有効にするか
    float4 color; //!< ライトの色
    float3 position; //!< ライトの位置
    float intensity; //!< 輝度
};

struct DirectionalLight
{
    float4 color; //!< ライトの色
    float3 direction; //!< ライトの向き(正規化必須)
    float intensity; //!< 輝度
};

struct UVTiling
{
    float2 tilingMultiply; //!< UVのタイリング係数
};

ConstantBuffer<Material> gMaterial : register(b0);
ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);
ConstantBuffer<UVTiling> gUVTiling : register(b2);
ConstantBuffer<Camera> gCamera : register(b3);
ConstantBuffer<Lighting> gLighting : register(b4);
ConstantBuffer<PointLight> gPointLight : register(b5);

struct PixelShaderOutput
{
    float4 color : SV_TARGET0;
};

Texture2D<float4> gTexture : register(t0);
SamplerState gSampler : register(s0);

PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;

    float4 transformedUV = mul(float4(input.texcoord, 0.0f, 1.0f), gMaterial.uvTransform);

    transformedUV.xy *= gUVTiling.tilingMultiply;

    float4 textureColor = gTexture.Sample(gSampler, transformedUV.xy);

    float3 toEye = normalize(gCamera.worldPosition - input.worldPosition);
    float3 reflectLight = reflect(gDirectionalLight.direction, normalize(input.normal));
    float RdotE = dot(reflectLight, toEye);
    float specularPow = pow(saturate(RdotE), gMaterial.shininess); // 反射強度
    
    float3 pointLightDir = normalize(gPointLight.position - input.worldPosition);


    if (gLighting.enableLighting != 0)
    {
        float cos;
        if (gLighting.lightingType == 0)
        {
            cos = saturate(dot(normalize(input.normal), -gDirectionalLight.direction));
        }
        else if (gLighting.lightingType == 1)
        {
            // half lambert
            float NdotL = dot(normalize(input.normal), -gDirectionalLight.direction);
            cos = pow(NdotL * 0.5f + 0.5f, 2.0f);
        }

        float3 diffuse = gMaterial.color.rgb * textureColor.rgb * gDirectionalLight.color.rgb * cos * gDirectionalLight.intensity;
        float3 specular = gDirectionalLight.color.rgb * gDirectionalLight.intensity * specularPow * float3(1.0f, 1.0f, 1.0f);

        /// ポイントライト
        if (gPointLight.enablePointLight == 1)
        {
            float distance = length(gPointLight.position - input.worldPosition); // ポイントライトへの距離
            if (distance < 0.1f) distance = 0.1f; // 0除算対策
            float factor = 1.0f / (distance * distance); // 距離の2乗に反比例する
            
            float3 pointLightDiffuse = gMaterial.color.rgb * textureColor.rgb * gPointLight.color.rgb * saturate(dot(input.normal, pointLightDir)) * gPointLight.intensity * factor;
            float3 pointLightSpecular = gPointLight.color.rgb * gPointLight.intensity * specularPow * float3(1.0f, 1.0f, 1.0f) * factor;
            
            output.color.rgb = diffuse + specular + pointLightDiffuse + pointLightSpecular;
        }
        else
        {
            output.color.rgb = diffuse + specular;
        }
        output.color.a = gMaterial.color.a * textureColor.a;
    }
    else
    {
        output.color = gMaterial.color * textureColor;
    }

    if (textureColor.a <= 0.f || output.color.a <= 0.f)
    {
        discard;
    }

    return output;
}