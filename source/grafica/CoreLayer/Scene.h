#pragma once
#ifndef SCENE
#define SCENE
#include "../CoreLayer/Input.h"
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

	private:
		Scene(Application& app);
		~Scene();
		void StartLoop() noexcept;
		void Update(float timeStep) noexcept;

		Input m_input;
		Application& m_application;
	};

}
#endif