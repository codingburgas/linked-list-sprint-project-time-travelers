workspace "TimeTravelers"
    startproject "TimeTravelers"
    architecture "x86_64"
    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TimeTravelers"
    location "TimeTravelers"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("./bin/" .. outputdir .. "/%{prj.name}")
    objdir ("./bin-int/" .. outputdir .. "/%{prj.name}")

    files { "./%{prj.name}/src/**.cpp", "./%{prj.name}/include/**.h", "./%{prj.name}/assets/**.png"}

    includedirs { "./%{prj.name}/src", "./%{prj.name}/include" }

    libdirs {"./%{prj.name}/include" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "OD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OD_RELEASE"
        optimize "On"