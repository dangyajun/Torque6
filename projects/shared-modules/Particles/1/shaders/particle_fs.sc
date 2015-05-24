$input v_position, v_texcoord0, v_color0

#include <torque6.sc>

SAMPLER2D(Texture0, 0);

void main()
{
    // Color
    vec4 color = texture2D(Texture0, v_texcoord0);
    color = color * v_color0;

    // OIT
    color.xyz *= color.w;
    float depth = v_position.z/v_position.w;
	float weight = color.w * clamp(0.03 / (1e-5 + pow(depth / 200.0, 5.0) ), 0.01, 3000.0);

	gl_FragData[0] = color * weight;
	gl_FragData[1] = vec4_splat(weight);
}
