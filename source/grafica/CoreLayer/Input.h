#pragma once
#ifndef INPUT
#define INPUT
#include <glm/glm.hpp>
#include <memory>

namespace Graficas
{
	/*
	* La clase Input provee una interfaz que permite al usuario hacer consultas sobre distintos dispositivos(teclado y mouse).
	* El motor internamente usa los metodos privados para actualizar cuando corresponda el estado de esta clase.
	*/
	class Input {

	public:
		/*
		* Enumerador que representa el estado del cursor. Hidden esconde la representacion visual del cursor al estar dentro
		* de la ventana de la aplicacion, mientras que Disabled como su nombre lo indica desabilita completamente el cursor.
		*/
		enum class CursorType { Hidden, Disabled, Normal };
		friend class World;
		Input();
		~Input();
		Input(const Input& input) = delete;
		Input& operator=(const Input& input) = delete;
		/*
		* Retorna verdadero si la tecla representada por keycode esta siendo presionada en este momento.
		*/
		bool IsKeyPressed(int keycode) const noexcept;
		/*
		* Retorna verdadero si el boton del mouse representado por button esta siendo presionado en este momento.
		*/
		bool IsMouseButtonPressed(int button) const noexcept;
		/*
		* Retorna un vector de dos dimensiones con la posicion en pixeles del mouse.
		* La posicion (0,0) corresponde a la esquina superior izquierda.
		*/
		glm::dvec2 GetMousePosition() const noexcept;
		/*
		* Retorna un vector de dos dimensiones con el offset de la rueda del mouse, usualmente unicamente la coordenada y sera distinta de cero.
		*/
		glm::dvec2 GetMouseWheelOffset() const noexcept;

		/*
		* Ajusta el tipo de cursor al tipo entregado
		*/
		void SetCursorType(CursorType type) noexcept;

		

		/*
		* Retorna verdadero si la combinacion de botones representada por chordcode esta siendo presionada en este momento.
		*/
		bool IsChordActive(int* keycodes) noexcept;


	
	
		/*
		* Funcion llamada cada iteracion del motor para actualizar el estado de los eventos de input
		*/
		void Update() noexcept;
		void StartUp() noexcept;
		void ShutDown() noexcept;

	private:
		class InputImplementation;
		std::unique_ptr<InputImplementation> p_Impl;
	};
}

#endif