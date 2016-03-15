/*
 * =====================================================================================
 *
 *       Filename: inputboard.hpp
 *        Created: 06/17/2015 10:24:27 PM
 *  Last Modified: 03/15/2016 00:07:38
 *
 *    Description: 
 *
 *        Version: 1.0
 *       Revision: none
 *       Compiler: gcc
 *
 *         Author: ANHONG
 *          Email: anhonghe@gmail.com
 *   Organization: USTC
 *
 * =====================================================================================
 */

#pragma once

#include <vector>
#include <string>
#include <SDL2/SDL.h>

#include "widget.hpp"
#include "tokenbox.hpp"
#include "imebase.hpp"

class InputBoard: public Widget
{
    public:
        InputBoard(int, int, uint8_t, uint8_t, uint32_t, int, uint32_t);
        virtual ~InputBoard();

    public:
        const char *Content();
        void SetContent(const char *);

    public:
        void SetFocus();
        bool Focus();

    public:
        void Draw();
        void Update(Uint32);
        bool ProcessEvent(const SDL_Event &);

    protected:
        virtual void Compile();

    protected:
        void SetProperH();
        void DrawCursor();
        void DrawSystemCursor();
        void PushBack(TOKENBOX &);
        void ResetShowStartX();
        void SetTokenBoxStartX();
        void BindCursorTokenBox(int, int);
        void LoadUTF8CharBoxCache(TOKENBOX &);

    protected:
        int      m_CursorWidth;
        uint32_t m_CursorColor;
        uint8_t  m_FontSet;
        uint8_t  m_Size;
        uint32_t m_TextColor;

    protected:
        int     m_SystemCursorX;
        int     m_SystemCursorY;
        bool    m_DrawOwnSystemCursor;
        int     m_BindTokenBoxIndex;
        int     m_ShowStartX;
        Uint32  m_Ticks;
        bool    m_Focus;

    protected:
        std::vector<TOKENBOX>       m_Line;
        std::string                 m_Content;

    public:
        static int  m_ShowSystemCursorCount;
        static int  m_InputBoxCount;

    private:
        IMEBase *m_IME;
};
