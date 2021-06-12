#pragma once

#include <exception>
#include <string>

namespace mio
{
    class exception : public std::exception
    {
    public:
        exception(std::string_view what);

        const char* what() const noexcept override;

    private:
        std::string what_;
    };

    class sdl_error : public exception
    {
    public:
        sdl_error();
    };

    class img_error : public exception
    {
    public:
        img_error();
    };

    class ttf_error : public exception
    {
    public:
        ttf_error();
    };

    class mix_error : public exception
    {
    public:
        mix_error();
    };
}
