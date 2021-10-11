#include "Scene.h"
#include <chrono>
namespace Graficas {

	Scene::Scene(Application& app) :
		m_input()
	{

		m_input.StartUp();
		m_application.StartUp(*this);

	}

	Scene::~Scene() {
		m_application.UserShutDown(*this);
		m_input.ShutDown();

	}

	

	Input& Scene::GetInput() noexcept {
		return m_input;
	}


	void Scene::StartLoop() noexcept {
		std::chrono::time_point<std::chrono::steady_clock> startTime = std::chrono::steady_clock::now();

		while (true)
		{
			std::chrono::time_point<std::chrono::steady_clock> newTime = std::chrono::steady_clock::now();
			const auto frameTime = newTime - startTime;
			startTime = newTime;
			float timeStep = std::chrono::duration_cast<std::chrono::duration<float>>(frameTime).count();
			Update(timeStep);
		}

	}

	void Scene::Update(float timeStep) noexcept
	{
		m_input.Update();
	}

}