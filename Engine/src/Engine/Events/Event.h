#pragma once
 
#include"Engine\Core.h"

#include<string>
#include<functional>

namespace Engine {
	
	//since the Egine is currently blocking ,it means that when vent 
	//occurs it gets dispatched immediatley and must be dealt right now,
	//TODO : Researchs required about the Buffer events in a event bus and process
	//them durig an event 


	enum class EventType //this class describes the event type
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus,WindowMoved, //the application events
		AppTick, AppUpdate, AppRender ,  //the application events
		KeyPressed, KeyReleased, //the Key events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled  //the Mouse events
	};

	//when we may want to filter certain events by reciveng all event form App class in to some 
	//event class but only focus about a certain event , for example log every keyboard events or 
	//mouse events
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),//since we know the value of the field group so we 
		EventCategoryInput		 = BIT(1),//create a data member with explicite size in bits
		EventCategoryKeyboard	 = BIT(2),
		EventCategoryMouse		 = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType()  { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override {return #type;}


#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}


	class ENGINE_API Event
	{
		//virtual ~Event() = default;
		friend class EventDispatcher;
		
		
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
		

		//this function asks if the event that pases to it is it in the event category or not 
		 bool IsInCategory(EventCategory category) 
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
		//this is a handled boolian to see if the evvent is handled or not
		//because further down the line where we start to dispatch event to dod various layers for
		//example is for us to decide to say i don't want ths to be propgated anyfurther 
	};

	//the dispatcher is to dispatchevents based on hteir type really easily 
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event){}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
	
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
 		return os << e.ToString();
	}
	
}
