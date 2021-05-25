workspace "Engine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	--Prekmake for the Engine project

--include directories relative to root folder  (solution directory) 
IncludeDir = {}--this is a struct which is going to be a list of include directories that we have	we use
--this is importnt because we want to have gflw directory in Engine , and the reason it is a struct becsuse iw
--will grow to include each dependency 
IncludeDir ["GLFW"]= "Engine/vendor/GLFW/include"
IncludeDir ["Glad"]= "Engine/vendor/Glad/include"
IncludeDir ["ImGui"]= "Engine/vendor/imgui"
IncludeDir["glm"] = "Engine/vendor/glm"

include "Engine/vendor/GLFW"--this will include the premake file in the glfw in to here
include "Engine/vendor/Glad"
include "Engine/vendor/imgui"




project "Engine"
	location "Engine"
	kind "sharedlib"
	language "c++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )

	pchheader "EGpch.h"
	pchsource "Engine/src/EGpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		--"%{prj.name}/src/Engine",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"	
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines
		{
			"EG_PLATFORM_WINDOWS",
			"EG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
			--"{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox"
			--"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}

	filter "configurations:Debug"
		defines "EG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "EG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "EG_Dist"
		runtime "Release"
		optimize "on"

-- premake for the sandbox project



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Engine/vendor/spdlog/include",
		"Engine/src/Engine",
		"Hazel/src",
		"%{IncludeDir.glm}"
		
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{	"EG_PLATFORM_WINDOWS",
			"SAND_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "DIST"
		runtime "Release"
		--optimize "On"