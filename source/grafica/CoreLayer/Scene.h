#pragma once
#ifndef SCENE
#define SCENE
#include "../CoreLayer/Input.h"
#include "../App.h"
#include <memory>
#include <array>
#include <filesystem>
#include <string>

namespace Graficas {

	class Material;
	class Scene {
	public:
		friend class Engine;

		Scene(const Scene& scene) = delete;
		Scene& operator=(const Scene& scene) = delete;

		Input& GetInput() noexcept;
		void SetTargetFPS(float target);

	private:
		Scene(App& app);
		~Scene();
		void StartLoop() noexcept;
		void Update(float timeStep) noexcept;

		Input m_input;
		App& m_application;
		float targetFps;
	};

}
#endif