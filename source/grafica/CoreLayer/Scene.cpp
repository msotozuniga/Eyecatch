#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Scene.h"
#include <chrono>
namespace Graficas {

	Scene::Scene(App& app) :
		m_input(),
		m_application(app)
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

	void Scene::SetTargetFPS(float target)
	{
		targetFps = 1 / target;
	}


	void Scene::StartLoop() noexcept {
		std::chrono::time_point<std::chrono::steady_clock> startTime = std::chrono::steady_clock::now();

		while (true)
		{
			std::chrono::time_point<std::chrono::steady_clock> newTime = std::chrono::steady_clock::now();
			const auto frameTime = newTime - startTime;
			startTime = newTime;
			float timeStep = std::chrono::duration_cast<std::chrono::duration<float>>(frameTime).count();
			timeStep > 1 ? Update(targetFps) : Update(timeStep);
			std::chrono::time_point<std::chrono::steady_clock> renderTime = std::chrono::steady_clock::now();
			auto elapsedTime = std::chrono::duration_cast<std::chrono::duration<float>>(renderTime-startTime).count();
			if (elapsedTime < targetFps) Sleep((targetFps - elapsedTime)*1000);
		}

	}

	void Scene::Update(float timeStep) noexcept
	{
		m_input.Update();
	}

}