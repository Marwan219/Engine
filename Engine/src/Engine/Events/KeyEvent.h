#pragma once

#include"EGpch.h"
#include"Engine\Events\Event.h"


namespace Engine 
{

	//the pressed class to be used in key pressed and key release
	class ENGINE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		
		EVENT_CLASS_CATEGORY( EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			:m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class ENGINE_API KeyPressedEvent : public KeyEvent
	{
	public://if it is a key code it measns that it wa spressedonce , if it it is repeatcount
		KeyPressedEvent(int keycode, int repeatCount)//that means the key has been pressed repeteady
			: KeyEvent(keycode), m_RepeatCount(repeatCount){}

		inline int  GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;//this code willl prints which key is pressed and how many times it was prressed
			ss << "KeyPressedEvent:" << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class ENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased Event: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};


	class ENGINE_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode){}


		std::string ToString() const override
		{
			std::stringstream ss;//this code willl prints which key is pressed and how many times it was prressed
			ss << "KeyTypedEvent:" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)

	};
}
