/*
JULIA-EXP-Z3
FRAGMENT SHADER

Julia exponencial. Cumple ecuación z_n = exp(z_n-1^3) + C.

@author Pablo Pizarro R. @ppizarror.com
@license MIT
@since 0.3.0
*/

// Activa precisión alta
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
precision mediump int;

// Pasa las coordenadas de cada punto (x,y) -> C
varying float c_r;
varying float c_i;

// Interaciones máximas
uniform int max_iterations;

// Rango de colores
uniform float r_min;
uniform float r_max;
uniform float g_min;
uniform float g_max;
uniform float b_min;
uniform float b_max;

// Constante c = j_re + i*j_im
uniform float j_re;
uniform float j_im;

// Inicio del shader
void main() {
	float r;
	float g;
	float b;
	float t;
	float w_r;
	float w_i;
	float u;
	float v;

	w_r = c_r;
	w_i = c_i;

	// Si converge es negro
	r = 0.0;
	g = 0.0;
	b = 0.0;

	for (int i = 0; i < 65536; i++) {
		u = w_r;
		v = w_i;

		w_r = exp(u*u*u - 3.0*u*v*v)*cos(3.0*u*u*v - v*v*v) + j_re;
		w_i = exp(u*u*u - 3.0*u*v*v)*sin(3.0*u*u*v - v*v*v) + j_im;

		if (w_r*w_r + w_i*w_i > 4.0) { // |z| > 2

		    // Computa el rojo
			t = log(float(i + 1)) / log(float(max_iterations + 1));
			r = t*r_max + (1.0 - t)*r_min;

			// Computa el verde
			// t = float(i + 1) / float(max_iterations + 1);
			g = t*g_max + (1.0 - t)*g_min;

            // Computa el azul
			// t = log(log(float(i + 1))) / log(log(float(max_iterations + 1)));
			b = t*b_max + (1.0 - t)*b_min;

			break;
		}

		if (i >= max_iterations) {
			break;
		}
	}

	gl_FragColor = vec4(r, g, b, 1.0);
}