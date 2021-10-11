#pragma once
#ifndef APP
#define APP
#include <memory>
namespace Graficas {
	class Input;
	class Scene;
	class App {
	public:
		friend class Scene;
		/*
		* Funcion virtual que el usuario del motor DEBE implementar al heredar de esta clase. Este metodo es llamado durante el proceso de
		* inicio del motor.
		*/
		virtual void UserStartUp(Scene& Scene) noexcept = 0;

		/*
		* Funcion virtual que el usuario del motor implementar al heredar de esta clase. Este metodo es llamado durante el proceso de cierre
		* del motor.
		*/
		virtual void UserShutDown(Scene& scene) noexcept = 0;

		/*
		* Funcion virtual que el usuario del motor implementar al heredar de esta clase. Este metodo es llamado cada iteraci�n del main loop del motor,
		* es aqui donde el usuario deberia correr logica general de su aplicaci�n.
		*/
		virtual void UserUpdate(Scene& scene, float timestep)  noexcept = 0;
		virtual ~App() = default;
	private:
		void StartUp(Scene& scene) noexcept;

	};
}
#endif