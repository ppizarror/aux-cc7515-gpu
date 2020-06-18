// (1)
glfwWindowHint(GLFW_SAMPLES, 4);			   // 4x antialiasing
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Define la versión de OpenGL
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   // Compatibilidad MacOS
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // No queremos el viejo OpenGL

// (2)
// Abre una ventana y crea el contexto de OpenGL
GLFWwindow *window;
// Variable global, para simplicidad
window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
if (window == NULL)
{
	fprintf(stderr, "Failed to open GLFW window.");
	glfwTerminate();
	return -1;
}

// (3)
glfwMakeContextCurrent(window); // Inicializa GLEW
glewExperimental = true;		// Se requiere en el core
if (glewInit() != GLEW_OK)
{
	fprintf(stderr, "Failed to initialize GLEW\n");
	return -1;
}

// (4)
// Aseguramos poder capturar los eventos del teclado presionados
glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
do
{
	// Borra la pantalla
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap buffers
	glfwSwapBuffers(window);
	glfwPollEvents();
} // Chequea que la tecla ESC haya sido presionada, si pasa eso se cierra la ventana
while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window) == 0);

// (5)
// Identifica el vertex buffer
GLuint vertexbuffer;
// Genera 1 buffer, pone el identificador resultante en vertexbuffer
glGenBuffers(1, &vertexbuffer);
// Los siguientes comandos se comunicarán con 'vertexbuffer'
glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
// Da los vértices a OpenGL
glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
	g_vertex_buffer_data, GL_STATIC_DRAW);

// (6)
// 1° atributo del buffer: vértices
glEnableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
glVertexAttribPointer(
	0, // Atributo N°0
	3, // Tamaño
	GL_FLOAT, // Tipo
	GL_FALSE, // Normalizado?
	0, // Stride
	(void*)0 // Array buffer offset
);
// Dibuja el triángulo
glDrawArrays(GL_TRIANGLES, 0, 3);
// Partiendo desde el vértice 0, 3 vértices totales -> 1 triángulo
glDisableVertexAttribArray(0);

// (7)
#version 330 core
// Input vertex data, diferente por cada ejecución de este shader
layout(location = 0) in vec3 vertexPosition_modelspace;
void main() {
	gl_Position.xyz = vertexPosition_modelspace;
	gl_Position.w = 1.0;
}

// (8)
// Crea el shader
GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
// Lee el código desde un archivo
std::string VertexShaderCode;
std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
if (VertexShaderStream.is_open()) {
	std::stringstream sstr;
	sstr << VertexShaderStream.rdbuf();
	VertexShaderCode = sstr.str();
	VertexShaderStream.close();
}

// (9)
// Compila el shader
printf("Compiling shader : %s\n", vertex_file_path);
char const * VertexSourcePointer = VertexShaderCode.c_str();
glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
glCompileShader(VertexShaderID);

// (10)
// Chequeo del shader
glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
if (InfoLogLength > 0) {
	std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
	glGetShaderInfoLog(
		VertexShaderID,
		InfoLogLength,
		NULL,
		&VertexShaderErrorMessage[0]
	);
	printf("%s\n", &VertexShaderErrorMessage[0]);
}

// (11)
// Link the program
printf("Linking program\n");
GLuint ProgramID = glCreateProgram();
glAttachShader(ProgramID, VertexShaderID);
glLinkProgram(ProgramID);

// (12)
#version 330 core
out vec3 color;
void main() {
	color = vec3(1, 0, 0);
}

// (13)
GLuint colorbuffer;
glGenBuffers(1, &colorbuffer);
glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data,
	GL_STATIC_DRAW);
// 2nd attribute buffer : colores
glEnableVertexAttribArray(1);
glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
glVertexAttribPointer(
	1, // Atributo N°1
	shader.
	3, // size
	GL_FLOAT, // type
	GL_FALSE, // normalized?
	0, // stride
	(void*)0 // array buffer offset
);

// (14)
// Activamos depth test
glEnable(GL_DEPTH_TEST);

// Activa profundidad entre la cámara y las superficies dibujadas con el fragment

glDepthFunc(GL_LESS);
// Borra la pantalla
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// (15)
#version 330 core
// Input del vertex, recordar las ubicaciones (0:posición, 1:colores)
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;
// Output data, lo que recibirá el fragment shader
out vec3 fragmentColor;
// Valores constantes para el mesh
uniform mat4 MVP;

void main() {
	// Posición del vértice en la ventana de clipping
	gl_Position = MVP * vec4(vertexPosition_modelspace, 1);

	// El color de cada vértice será interpolado para producir el color en el fragment
	fragmentColor = vertexColor;
}

// 16
#version 330 core
// Color interpolado desde el vertex shader
in vec3 fragmentColor;
// Ouput data
out vec3 color;
void main() {
	// Color (output), se interpolará por los tres vértices de cada cara
	color = fragmentColor;
}

// 17
# List of geometric vertices, with(x, y, z[, w])
coordinates, w is optional and defaults to 1.0.
v 0.123 0.234 0.345 1.0
v ...
...
# List of texture coordinates, in(u, v[, w])
coordinates, these will vary between 0 and 1, w is
optional and defaults to 0.
vt 0.500 1[0]
vt ...
...
# List of vertex normals in(x, y, z) form; normals
might not be unit vectors.
vn 0.707 0.000 0.707
vn ...
...
# Parameter space vertices in(u[, v][, w]) form; free
form geometry statement(see below)
vp 0.310000 3.210000 2.100000
vp ...
...
# Polygonal face element(see below)
f 1 2 3
f 3 / 1 4 / 2 5 / 3
f 6 / 4 / 1 3 / 5 / 3 7 / 6 / 5
f 7//1 8//2 9//3
f ...
...
# Line element(see below)
l 5 8 1 2 4 9