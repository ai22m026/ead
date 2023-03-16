workspace "Pigskin"
	architecture "x86_64"
	startproject "Pigskin"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PigSkin"
	location "pigskin"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:Windows"
		staticruntime "on"
		systemversion "10.0.22000.0"

		defines
		{
			"PS_BUILD_DLL",
			"PS_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines "PS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PS_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"PigSkin/vendor/spdlog/include",
		"Pigskin/src"
	}

	links
	{
		"Pigskin"
	}

	filter "system:windows"
		staticruntime "on"
		systemversion "10.0.22000.0"

		defines
		{
			"PS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PS_DIST"
		optimize "On"
