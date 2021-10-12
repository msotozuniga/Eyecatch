#pragma once
#ifndef ENGINE
#define ENGINE
#include "CoreLayer/Scene.h"
#include <memory>
#include "App.h"
namespace Graficas {
	class Engine
	{
	public:
		Engine(App& app) : m_scene(app) {}
		~Engine() = default;
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		/*
		* Funcion que comienza el main loop del motor.
		*/
		void StartMainLoop() noexcept {
			m_scene.StartLoop();
		}
	private:
		Scene m_scene;
	};
}

#endif