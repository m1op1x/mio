#include <mio/detail/scancode.hpp>

#include <mio/exception.hpp>

namespace mio::detail
{
    scancode convert_scancode(SDL_Scancode scancode)
    {
        switch (scancode)
        {
            case SDL_SCANCODE_A:
            {
                return scancode::a;
            }
            case SDL_SCANCODE_B:
            {
                return scancode::b;
            }
            case SDL_SCANCODE_C:
            {
                return scancode::c;
            }
            case SDL_SCANCODE_D:
            {
                return scancode::d;
            }
            case SDL_SCANCODE_E:
            {
                return scancode::e;
            }
            case SDL_SCANCODE_F:
            {
                return scancode::f;
            }
            case SDL_SCANCODE_G:
            {
                return scancode::g;
            }
            case SDL_SCANCODE_H:
            {
                return scancode::h;
            }
            case SDL_SCANCODE_I:
            {
                return scancode::i;
            }
            case SDL_SCANCODE_J:
            {
                return scancode::j;
            }
            case SDL_SCANCODE_K:
            {
                return scancode::k;
            }
            case SDL_SCANCODE_L:
            {
                return scancode::l;
            }
            case SDL_SCANCODE_M:
            {
                return scancode::m;
            }
            case SDL_SCANCODE_N:
            {
                return scancode::n;
            }
            case SDL_SCANCODE_O:
            {
                return scancode::o;
            }
            case SDL_SCANCODE_P:
            {
                return scancode::p;
            }
            case SDL_SCANCODE_Q:
            {
                return scancode::q;
            }
            case SDL_SCANCODE_R:
            {
                return scancode::r;
            }
            case SDL_SCANCODE_S:
            {
                return scancode::s;
            }
            case SDL_SCANCODE_T:
            {
                return scancode::t;
            }
            case SDL_SCANCODE_U:
            {
                return scancode::u;
            }
            case SDL_SCANCODE_V:
            {
                return scancode::v;
            }
            case SDL_SCANCODE_W:
            {
                return scancode::w;
            }
            case SDL_SCANCODE_X:
            {
                return scancode::x;
            }
            case SDL_SCANCODE_Y:
            {
                return scancode::y;
            }
            case SDL_SCANCODE_Z:
            {
                return scancode::z;
            }
            case SDL_SCANCODE_0:
            {
                return scancode::n0;
            }
            case SDL_SCANCODE_1:
            {
                return scancode::n1;
            }
            case SDL_SCANCODE_2:
            {
                return scancode::n2;
            }
            case SDL_SCANCODE_3:
            {
                return scancode::n3;
            }
            case SDL_SCANCODE_4:
            {
                return scancode::n4;
            }
            case SDL_SCANCODE_5:
            {
                return scancode::n5;
            }
            case SDL_SCANCODE_6:
            {
                return scancode::n6;
            }
            case SDL_SCANCODE_7:
            {
                return scancode::n7;
            }
            case SDL_SCANCODE_8:
            {
                return scancode::n8;
            }
            case SDL_SCANCODE_9:
            {
                return scancode::n9;
            }
            case SDL_SCANCODE_RETURN:
            {
                return scancode::enter;
            }
            case SDL_SCANCODE_ESCAPE:
            {
                return scancode::escape;
            }
            case SDL_SCANCODE_BACKSPACE:
            {
                return scancode::backspace;
            }
            case SDL_SCANCODE_TAB:
            {
                return scancode::tab;
            }
            case SDL_SCANCODE_SPACE:
            {
                return scancode::space;
            }
            case SDL_SCANCODE_MINUS:
            {
                return scancode::minus;
            }
            case SDL_SCANCODE_EQUALS:
            {
                return scancode::equal;
            }
            case SDL_SCANCODE_LEFTBRACKET:
            {
                return scancode::left_bracket;
            }
            case SDL_SCANCODE_RIGHTBRACKET:
            {
                return scancode::right_bracket;
            }
            case SDL_SCANCODE_BACKSLASH:
            {
                return scancode::backslash;
            }
            case SDL_SCANCODE_SEMICOLON:
            {
                return scancode::semicolon;
            }
            case SDL_SCANCODE_APOSTROPHE:
            {
                return scancode::apostrophe;
            }
            case SDL_SCANCODE_GRAVE:
            {
                return scancode::grave_accent;
            }
            case SDL_SCANCODE_COMMA:
            {
                return scancode::comma;
            }
            case SDL_SCANCODE_PERIOD:
            {
                return scancode::period;
            }
            case SDL_SCANCODE_SLASH:
            {
                return scancode::slash;
            }
            case SDL_SCANCODE_CAPSLOCK:
            {
                return scancode::caps_lock;
            }
            case SDL_SCANCODE_F1:
            {
                return scancode::f1;
            }
            case SDL_SCANCODE_F2:
            {
                return scancode::f2;
            }
            case SDL_SCANCODE_F3:
            {
                return scancode::f3;
            }
            case SDL_SCANCODE_F4:
            {
                return scancode::f4;
            }
            case SDL_SCANCODE_F5:
            {
                return scancode::f5;
            }
            case SDL_SCANCODE_F6:
            {
                return scancode::f6;
            }
            case SDL_SCANCODE_F7:
            {
                return scancode::f7;
            }
            case SDL_SCANCODE_F8:
            {
                return scancode::f8;
            }
            case SDL_SCANCODE_F9:
            {
                return scancode::f9;
            }
            case SDL_SCANCODE_F10:
            {
                return scancode::f10;
            }
            case SDL_SCANCODE_F11:
            {
                return scancode::f11;
            }
            case SDL_SCANCODE_F12:
            {
                return scancode::f12;
            }
            case SDL_SCANCODE_PRINTSCREEN:
            {
                return scancode::print_screen;
            }
            case SDL_SCANCODE_SCROLLLOCK:
            {
                return scancode::scroll_lock;
            }
            case SDL_SCANCODE_PAUSE:
            {
                return scancode::pause;
            }
            case SDL_SCANCODE_INSERT:
            {
                return scancode::insert;
            }
            case SDL_SCANCODE_HOME:
            {
                return scancode::home;
            }
            case SDL_SCANCODE_PAGEUP:
            {
                return scancode::page_up;
            }
            case SDL_SCANCODE_DELETE:
            {
                return scancode::delete_;
            }
            case SDL_SCANCODE_END:
            {
                return scancode::end;
            }
            case SDL_SCANCODE_PAGEDOWN:
            {
                return scancode::page_down;
            }
            case SDL_SCANCODE_RIGHT:
            {
                return scancode::right;
            }
            case SDL_SCANCODE_LEFT:
            {
                return scancode::left;
            }
            case SDL_SCANCODE_DOWN:
            {
                return scancode::down;
            }
            case SDL_SCANCODE_UP:
            {
                return scancode::up;
            }
            case SDL_SCANCODE_NUMLOCKCLEAR:
            {
                return scancode::num_lock;
            }
            case SDL_SCANCODE_MENU:
            {
                return scancode::menu;
            }
            case SDL_SCANCODE_LCTRL:
            {
                return scancode::left_control;
            }
            case SDL_SCANCODE_LSHIFT:
            {
                return scancode::left_shift;
            }
            case SDL_SCANCODE_LALT:
            {
                return scancode::left_alt;
            }
            case SDL_SCANCODE_LGUI:
            {
                return scancode::left_super;
            }
            case SDL_SCANCODE_RCTRL:
            {
                return scancode::right_control;
            }
            case SDL_SCANCODE_RSHIFT:
            {
                return scancode::right_shift;
            }
            case SDL_SCANCODE_RALT:
            {
                return scancode::right_alt;
            }
            case SDL_SCANCODE_RGUI:
            {
                return scancode::right_super;
            }
            default:
            {
                throw exception("Invalid keyboard key");
            }
        }
    }

    SDL_Scancode convert_scancode(scancode key)
    {
        switch (key)
        {
            case scancode::a:
            {
                return SDL_SCANCODE_A;
            }
            case scancode::b:
            {
                return SDL_SCANCODE_B;
            }
            case scancode::c:
            {
                return SDL_SCANCODE_C;
            }
            case scancode::d:
            {
                return SDL_SCANCODE_D;
            }
            case scancode::e:
            {
                return SDL_SCANCODE_E;
            }
            case scancode::f:
            {
                return SDL_SCANCODE_F;
            }
            case scancode::g:
            {
                return SDL_SCANCODE_G;
            }
            case scancode::h:
            {
                return SDL_SCANCODE_H;
            }
            case scancode::i:
            {
                return SDL_SCANCODE_I;
            }
            case scancode::j:
            {
                return SDL_SCANCODE_J;
            }
            case scancode::k:
            {
                return SDL_SCANCODE_K;
            }
            case scancode::l:
            {
                return SDL_SCANCODE_L;
            }
            case scancode::m:
            {
                return SDL_SCANCODE_M;
            }
            case scancode::n:
            {
                return SDL_SCANCODE_N;
            }
            case scancode::o:
            {
                return SDL_SCANCODE_O;
            }
            case scancode::p:
            {
                return SDL_SCANCODE_P;
            }
            case scancode::q:
            {
                return SDL_SCANCODE_Q;
            }
            case scancode::r:
            {
                return SDL_SCANCODE_R;
            }
            case scancode::s:
            {
                return SDL_SCANCODE_S;
            }
            case scancode::t:
            {
                return SDL_SCANCODE_T;
            }
            case scancode::u:
            {
                return SDL_SCANCODE_U;
            }
            case scancode::v:
            {
                return SDL_SCANCODE_V;
            }
            case scancode::w:
            {
                return SDL_SCANCODE_W;
            }
            case scancode::x:
            {
                return SDL_SCANCODE_X;
            }
            case scancode::y:
            {
                return SDL_SCANCODE_Y;
            }
            case scancode::z:
            {
                return SDL_SCANCODE_Z;
            }
            case scancode::n0:
            {
                return SDL_SCANCODE_0;
            }
            case scancode::n1:
            {
                return SDL_SCANCODE_1;
            }
            case scancode::n2:
            {
                return SDL_SCANCODE_2;
            }
            case scancode::n3:
            {
                return SDL_SCANCODE_3;
            }
            case scancode::n4:
            {
                return SDL_SCANCODE_4;
            }
            case scancode::n5:
            {
                return SDL_SCANCODE_5;
            }
            case scancode::n6:
            {
                return SDL_SCANCODE_6;
            }
            case scancode::n7:
            {
                return SDL_SCANCODE_7;
            }
            case scancode::n8:
            {
                return SDL_SCANCODE_8;
            }
            case scancode::n9:
            {
                return SDL_SCANCODE_9;
            }
            case scancode::enter:
            {
                return SDL_SCANCODE_RETURN;
            }
            case scancode::escape:
            {
                return SDL_SCANCODE_ESCAPE;
            }
            case scancode::backspace:
            {
                return SDL_SCANCODE_BACKSPACE;
            }
            case scancode::tab:
            {
                return SDL_SCANCODE_TAB;
            }
            case scancode::space:
            {
                return SDL_SCANCODE_SPACE;
            }
            case scancode::minus:
            {
                return SDL_SCANCODE_MINUS;
            }
            case scancode::equal:
            {
                return SDL_SCANCODE_EQUALS;
            }
            case scancode::left_bracket:
            {
                return SDL_SCANCODE_LEFTBRACKET;
            }
            case scancode::right_bracket:
            {
                return SDL_SCANCODE_RIGHTBRACKET;
            }
            case scancode::backslash:
            {
                return SDL_SCANCODE_BACKSLASH;
            }
            case scancode::semicolon:
            {
                return SDL_SCANCODE_SEMICOLON;
            }
            case scancode::apostrophe:
            {
                return SDL_SCANCODE_APOSTROPHE;
            }
            case scancode::grave_accent:
            {
                return SDL_SCANCODE_GRAVE;
            }
            case scancode::comma:
            {
                return SDL_SCANCODE_COMMA;
            }
            case scancode::period:
            {
                return SDL_SCANCODE_PERIOD;
            }
            case scancode::slash:
            {
                return SDL_SCANCODE_SLASH;
            }
            case scancode::caps_lock:
            {
                return SDL_SCANCODE_CAPSLOCK;
            }
            case scancode::f1:
            {
                return SDL_SCANCODE_F1;
            }
            case scancode::f2:
            {
                return SDL_SCANCODE_F2;
            }
            case scancode::f3:
            {
                return SDL_SCANCODE_F3;
            }
            case scancode::f4:
            {
                return SDL_SCANCODE_F4;
            }
            case scancode::f5:
            {
                return SDL_SCANCODE_F5;
            }
            case scancode::f6:
            {
                return SDL_SCANCODE_F6;
            }
            case scancode::f7:
            {
                return SDL_SCANCODE_F7;
            }
            case scancode::f8:
            {
                return SDL_SCANCODE_F8;
            }
            case scancode::f9:
            {
                return SDL_SCANCODE_F9;
            }
            case scancode::f10:
            {
                return SDL_SCANCODE_F10;
            }
            case scancode::f11:
            {
                return SDL_SCANCODE_F11;
            }
            case scancode::f12:
            {
                return SDL_SCANCODE_F12;
            }
            case scancode::print_screen:
            {
                return SDL_SCANCODE_PRINTSCREEN;
            }
            case scancode::scroll_lock:
            {
                return SDL_SCANCODE_SCROLLLOCK;
            }
            case scancode::pause:
            {
                return SDL_SCANCODE_PAUSE;
            }
            case scancode::insert:
            {
                return SDL_SCANCODE_INSERT;
            }
            case scancode::home:
            {
                return SDL_SCANCODE_HOME;
            }
            case scancode::page_up:
            {
                return SDL_SCANCODE_PAGEUP;
            }
            case scancode::delete_:
            {
                return SDL_SCANCODE_DELETE;
            }
            case scancode::end:
            {
                return SDL_SCANCODE_END;
            }
            case scancode::page_down:
            {
                return SDL_SCANCODE_PAGEDOWN;
            }
            case scancode::right:
            {
                return SDL_SCANCODE_RIGHT;
            }
            case scancode::left:
            {
                return SDL_SCANCODE_LEFT;
            }
            case scancode::down:
            {
                return SDL_SCANCODE_DOWN;
            }
            case scancode::up:
            {
                return SDL_SCANCODE_UP;
            }
            case scancode::num_lock:
            {
                return SDL_SCANCODE_NUMLOCKCLEAR;
            }
            case scancode::menu:
            {
                return SDL_SCANCODE_MENU;
            }
            case scancode::left_control:
            {
                return SDL_SCANCODE_LCTRL;
            }
            case scancode::left_shift:
            {
                return SDL_SCANCODE_LSHIFT;
            }
            case scancode::left_alt:
            {
                return SDL_SCANCODE_LALT;
            }
            case scancode::left_super:
            {
                return SDL_SCANCODE_LGUI;
            }
            case scancode::right_control:
            {
                return SDL_SCANCODE_RCTRL;
            }
            case scancode::right_shift:
            {
                return SDL_SCANCODE_RSHIFT;
            }
            case scancode::right_alt:
            {
                return SDL_SCANCODE_RALT;
            }
            case scancode::right_super:
            {
                return SDL_SCANCODE_RGUI;
            }
            default:
            {
                throw exception("Invalid keyboard key");
            }
        }
    }
}
