workspace "brayjlEngine"
	architecture "x64"

	configurations {
		"Debug",
		"Release"
	}

	startproject "sandbox"

project "brayjl"
	kind "StaticLib"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"
	objdir "bin/%{cfg.buildcfg}/obj"
	location "brayjl"

	files {
		"brayjl/**.hpp",
		"brayjl/**.h",
		"brayjl/**.cpp",
	}

	includedirs {
		"brayjl/source",
		"dependencies/spdlog/include",
		"dependencies/glfw/include"
	}

	libdirs {
		"dependencies/glfw/lib-vc2015"
	}

	links {
		"glfw3",
		"opengl32"
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

project "sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"
	objdir "bin/%{cfg.buildcfg}/obj"
	location "sandbox"

	files {
		"sandbox/**.hpp",
		"sandbox/**.h",
		"sandbox/**.cpp",
	}

	includedirs {
		"brayjl/source",
		"dependencies/spdlog/include",
		"dependencies/glfw/include"
	}

	libdirs {
		"dependencies/glfw/lib-vc2015"
	}

	links {
		"brayjl",
		"glfw3",
		"opengl32"
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"