workspace "TimeTravelers"
    startproject "PL"
    architecture "x86_64"
    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Presentation Layer (PL)
project "PL"
    location "TimeTravelers/PL"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { "./TimeTravelers/PL/src/**.cpp", "./TimeTravelers/PL/include/**.h", "TimeTravelers/PL/assets/**.png" }
    
    includedirs { "./TimeTravelers/PL/include", "./TimeTravelers/BLL/include", "./TimeTravelers/DAL/include", "./vendor/json/include" }

    libdirs { "bin/" .. outputdir .. "/BLL", "bin/" .. outputdir .. "/DAL" }
    
    links { "BLL", "DAL" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "PL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PL_RELEASE"
        optimize "On"

-- Business Logic Layer (BLL)
project "BLL"
    location "TimeTravelers/BLL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/" .. outputdir .. "/TimeTravelers/BLL")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { "./TimeTravelers/BLL/src/**.cpp", "./TimeTravelers/BLL/include/**.h" }

    includedirs { "./TimeTravelers/BLL/include", "./vendor/json/include" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "BLL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BLL_RELEASE"
        optimize "On"

-- Data Access Layer (DAL)
project "DAL"
    location "TimeTravelers/DAL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/" .. outputdir .. "/TimeTravelers/DAL")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { "./TimeTravelers/DAL/src/**.cpp", "./TimeTravelers/DAL/include/**.h" }
    includedirs { "./TimeTravelers/DAL/include", "./vendor/json/include" }

    staticruntime "On"
    systemversion "latest"

    filter "configurations:Debug"
        defines "DAL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "DAL_RELEASE"
        optimize "On"