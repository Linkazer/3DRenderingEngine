#include <Rendering\OpenGL\OpenglRenderProvider.h>

#include <format>

//OpenGL
#include <glad\glad.h>
#include <Engine\Window\WindowSystem.h>
#include <Rendering\OpenGL\Data\OpenglMeshData.h>

//Logs
#include <Engine\LogSystem\LogSystem.h>

OpenglRenderProvider::OpenglRenderProvider()
	: shader(OpenglShader())
{}

bool OpenglRenderProvider::Initialize()
{
	if (!gladLoadGLLoader(((GLADloadproc)WindowSystem::GetProcAdress)))
	{
		LogSystem::LogError("Glad couldn't load.");
		return false;
	}
	
	//Shader
	shader.LoadShader("ressources/Shaders/BasicShader/BasicShader.vs", "ressources/Shaders/BasicShader/BasicShader.fs");

	return true;
}

void OpenglRenderProvider::Clean()
{
	//TODO : Clean les Renderers
	renderers.clear();
}

void OpenglRenderProvider::Render(const Camera& camera)
{
	// --- Setup de la boucle ---
	glEnable(GL_DEPTH_TEST);

	// - Clear les buffers et la couleur de fond
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// - Setup du shader
	shader.Use();

	// - Récupération des matrices
	//  - Matrice de vue
	glm::mat4 viewMat = camera.GetViewMatrix();
	shader.SetMat4("view", viewMat);

	//  - Matrice de projection
	glm::mat4 projMat = camera.GetProjectionMatrix();
	shader.SetMat4("projection", projMat);

	//  - Matrice de position
	//glm::vec3 viewPos = camera.GetTransform().GetPosition();

	// --- Rendu des objets ---
	for (int i = 0; i < renderers.size(); i++)
	{
		// - Matrice de modèle
		glm::mat4 modelMat = renderers[i]->GetTransform().GetModelMatrix();
		shader.SetMat4("model", modelMat);

		// -- Rendu des meshes d'un object --
		for (const OpenglMeshData& meshData : renderers[i]->GetMeshes())
		{
			// -- Rendu d'OpenGL --
			glBindVertexArray(meshData.GetVao());
			glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(meshData.GetIndices().size()), GL_UNSIGNED_INT, 0);
		}

		std::string runtimeChosen;

		LogSystem::Log(std::format("Render Opengl : Renderer nb {}", i+1));
	}

	glBindVertexArray(0);
}

void OpenglRenderProvider::AddApiRendererToRenderLoop(OpenglRenderer* rendererToAdd)
{
	if (std::find(begin(renderers), end(renderers), rendererToAdd) == end(renderers))
	{
		renderers.push_back(rendererToAdd);
	}
}

void OpenglRenderProvider::RemoveApiRendererToRenderLoop(OpenglRenderer* rendererToRemove)
{
	renderers.erase(
		std::remove(renderers.begin(), renderers.end(), rendererToRemove), renderers.end()
	);
}
