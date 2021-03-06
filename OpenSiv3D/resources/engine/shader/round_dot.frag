#version 300 es

precision mediump float;

layout(std140) uniform PSConstants2D
{
	vec4 g_colorAdd;
	vec4 g_sdfParam;
	vec4 g_internal;	
};

//
// PSInput
//
in vec4 Color;
in vec2 UV;

//
// PSOutput
//
layout(location = 0) out vec4 FragColor;
		
void main()
{
	float t = mod(UV.x, 2.0);
	vec2 tex = UV;
	tex.x = abs(1.0 - t) * 2.0;
	vec4 color = Color;
	color.a *= 1.0 - clamp(pow(dot(tex, tex), 8.0), 0.0, 1.0);
	
	FragColor = color + g_colorAdd;
}
