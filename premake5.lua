workspace "Ravi"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ravi"
	location "Ravi"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rvpch.h"
	pchsource "Ravi/src/rvpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"RV_PLATFORM_WINDOWS",
			"RV_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RV_Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RV_DIST"
		optimize "On"

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
		"Ravi/vendor/spdlog/include",
		"Ravi/src"
	}

	links
	{
		"Ravi"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"RV_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RV_Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RV_DIST"
		optimize "On"