#include <Rendering\OpenGL\Data\OpenglMeshData.h>

#include <glad\glad.h>

OpenglMeshData::OpenglMeshData()
	: MeshData()
{
	// Création des buffers
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	// Binding des buffers (Pour traailler dessus)
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexData), &vertices[0], GL_STATIC_DRAW); //Remplissage du buffer de Vertex

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW); // Remplissage du buffer d'Element

	// Création des attributs de vertices
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, normal));

	// Reset du binding
	glBindVertexArray(0);
}
