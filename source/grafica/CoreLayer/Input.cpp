#include "Input.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <map>
//#include "../Core/Common.hpp"
//#include "../Core/Log.hpp"
//#include "../Event/EventManager.hpp"
//#include "../Event/Events.hpp"

namespace Graficas
{
	class Input::InputImplementation {
	private:

		typedef std::map<int, int>  KeyMap;
		GLFWwindow* m_windowHandle;
		glm::dvec2 m_mouseWheelOffset;
		KeyMap keyPresses;
		

	public:
		InputImplementation() :m_windowHandle(nullptr), m_mouseWheelOffset(0.0, 0.0)
		{
			
		}

		void StartUp() noexcept { 
			m_windowHandle = glfwGetCurrentContext();
		}

		void ShutDown() noexcept {
			return;
		}
		void Update() noexcept {
			m_mouseWheelOffset.x = 0.0;
			m_mouseWheelOffset.y = 0.0;
			glfwPollEvents();
			for (auto it = keyPresses.begin(); it != keyPresses.end(); ++it)
			{
				it->second--;
			}
		}
		/*
		void OnMouseScroll(const MouseScrollEvent& e)
		{
			m_mouseWheelOffset = glm::dvec2(e.xOffset, e.yOffset);
		}*/
		inline bool IsKeyPressed(int keycode) noexcept
		{
			if (glfwGetKey(m_windowHandle, keycode) == GLFW_PRESS) {
				keyPresses[keycode] = 3;
			}
			return glfwGetKey(m_windowHandle, keycode) == GLFW_RELEASE;
		}

		void RegisterKey(int keycode) noexcept {
			keyPresses[keycode] = 0;
		}

		bool IsChordActive(int *keycodes) noexcept {
			size_t lenght = sizeof(keycodes) / sizeof(keycodes[0]);
			bool active = true;
			for (size_t index = 0; index < lenght; index++)
			{
				IsKeyPressed(keycodes[index]);
				active = keyPresses[keycodes[index]] > 0 ? active : false;
			}
			return active;
		}



		inline bool IsMouseButtonPressed(int button) const noexcept {
			return glfwGetMouseButton(m_windowHandle, button) == GLFW_PRESS;
		}
		inline glm::dvec2 GetMousePosition() const noexcept {
			double x, y;
			glfwGetCursorPos(m_windowHandle, &x, &y);
			return glm::dvec2(x, y);
		}
		inline glm::dvec2 GetMouseWheelOffset() const noexcept {
			return m_mouseWheelOffset;
		}
		void SetCursorType(CursorType type) noexcept
		{
			switch (type)
			{
			case CursorType::Disabled:
			{
				glfwSetInputMode(m_windowHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
				return;
			}
			case CursorType::Hidden:
			{
				glfwSetInputMode(m_windowHandle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
				return;
			}
			case CursorType::Normal:
			{
				glfwSetInputMode(m_windowHandle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
				return;
			}

			}
		}
	

	};

	Input::Input() : p_Impl(std::make_unique<InputImplementation>()) {}

	Input::~Input() = default;

	void Input::Update() noexcept
	{
		p_Impl->Update();
	}

	bool Input::IsKeyPressed(int keycode) const noexcept
	{
		return p_Impl->IsKeyPressed(keycode);
	}

	bool Input::IsChordActive(int* keycodes) noexcept
	{
		return p_Impl->IsChordActive(keycodes);
	}

	bool Input::IsMouseButtonPressed(int button) const noexcept
	{
		return p_Impl->IsMouseButtonPressed(button);
	}

	glm::dvec2 Input::GetMousePosition() const noexcept
	{
		return p_Impl->GetMousePosition();
	}

	glm::dvec2 Input::GetMouseWheelOffset() const noexcept
	{
		return p_Impl->GetMouseWheelOffset();
	}
	void Input::SetCursorType(CursorType type) noexcept
	{
		p_Impl->SetCursorType(type);
	}


	void Input::StartUp() noexcept {
		p_Impl->StartUp();
	}

	void Input::ShutDown() noexcept {
		p_Impl->ShutDown();
	}



}