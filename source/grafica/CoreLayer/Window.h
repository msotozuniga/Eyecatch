#pragma once
#ifndef WINDOW
#define WINDOW
#include <memory>
#include <glm/glm.hpp>
namespace Graficas
{
	class Scene;
	class EventManager;
	/*
	* La clase Window provee una interfaz que permite al usario configurar y/o consultar informaci�n de la ventana de la aplicaci�n.
	*/
	class Window {
	public:
		friend class World;
		Window();
		~Window();
		Window(const Window& window) = delete;
		Window& operator=(const Window& window) = delete;

		/*
		* Retorna verdadero si la ventana de la aplicaci�n esta en modo pantalla completa.
		*/
		bool IsFullScreen() const noexcept;

		/*
		* Ajusta
		*/
		void SetFullScreen(bool value) noexcept;

		/*
		*
		*/
		bool ShouldClose() const noexcept;

		/*
		*
		*/
		void SetSwapInterval(int interval) noexcept;

		/*
		*
		*/
		glm::ivec2 GetWindowDimensions() const noexcept;

		/*
		*
		*/
		glm::ivec2 GetWindowFrameBufferSize() const noexcept;

		/*
		*
		*/
		void SetWindowDimensions(const glm::ivec2& dimensions) noexcept;
	
		void StartUp() noexcept;
		void ShutDown() noexcept;
		void Update() noexcept;

	private:
		class WindowImplementation;
		std::unique_ptr<WindowImplementation> p_Impl;
	};
}
#endif