workspace "Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	--Prekmake for the Engine project

--include directories relative to root folder  (solution directory) 
IncludeDir={}--this is a struct which is going to be a list of include directories that we have	we use
--this is importnt because we want to have gflw directory in Engine , and the reason it is a struct becsuse iw
--will grow to include each dependency 
IncludeDir ["GLFW"]= "Engine/vendor/GLFW/include"

include "Engine/vendor/GLFW"--this will include the premake file in the glfw in to here

project "Engine"
	location "Engine"
	kind "sharedlib"
	language "c++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )

	pchheader "EGpch.h"
	pchsource "Engine/src/EGpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		--"%{prj.name}/src/Engine",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"EG_PLATFORM_WINDOWS",
			"EG_BUILD_DLL",
		}

		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox"
			--"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}

	filter "configurations:Debug"
		defines "EG_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "EG_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "EG_Dist"
		optimize "on"

-- premake for the sandbox project



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Engine/src",
		"Engine/src/Engine"
		
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{	"EG_PLATFORM_WINDOWS",
			"SAND_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DIST"
		optimize "On"