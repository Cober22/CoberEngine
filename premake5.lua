workspace "Cober" 
	architecture "x64"
	startproject "Sandbox"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Cober"
	location "Cober"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Cober/src/pch.cpp" 

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/libraries/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"CB_PLATFORM_WINDOWS",
			"CB_BUILD_DLL"
		}

		postbuildcommands
		{
			{"{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox"}
		}

	filter "configurations:Debug"
		defines "CB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CB_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Cober/libraries/spdlog/include",
		"Cober/src"
	}

	links 
	{
		"Cober"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"CB_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "CB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CB_DIST"
		optimize "On"
