/*
 * =====================================================================================
 *
 *       Filename: emoticondbn.hpp
 *        Created: 03/17/2016 01:17:51
 *  Last Modified: 03/18/2016 12:10:25
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
#include "emoticondb.hpp"

#define EMOTICONDBN_LC_DEPTH  (2              )
#define EMOTICONDBN_LC_LENGTH (2048           )
#define EMOTICONDBN_CAPACITY  (2 * 2048 + 1024)

using EmoticonDBType = EmoticonDB<
    EMOTICONDBN_LC_DEPTH,EMOTICONDBN_LC_LENGTH, EMOTICONDBN_CAPACITY>;

class EmoticonDBN: public EmoticonDBType
{
    public:
        EmoticonDBN(): EmoticonDBType()
        {
            extern EmoticonDBN *g_EmoticonDBN;
            if(g_EmoticonDBN){
                throw std::runtime_error("one instance for EmoticonDBN please");
            }
        }

        virtual ~EmoticonDBN() = default;

    public:
        SDL_Texture *Retrieve(uint32_t nKey,
                int *pSrcX, int *pSrcY, int *pSrcW, int *pSrcH, int *pFrameCount)
        {
            const auto &fnLinearCacheKey = [&](uint32_t nKey)
            {
                return (nKey <<= 8) % EMOTICONDBN_LC_LENGTH;
            };

            EmoticonItem stItem;
            RetrieveItem(nKey & 0XFFFFFF00, &stItem, fnLinearCacheKey);

            // failed to retrieve, return directly without setting anything
            if(!stItem.Texture){ return nullptr; }

            int nW, nH, nCountX, nCountY;
            SDL_QueryTexture(stItem.Texture, nullptr, nullptr, &nW, &nH);

            nCountX = nW / stItem.FrameW;
            nCountY = nH / stItem.FrameH;

            int nFrameIndex = (int)(nKey & 0X000000FF);

            if(*pSrcX){ *pSrcX = (nFrameIndex % nCountX) * stItem.FrameW; };
            if(*pSrcY){ *pSrcY = (nFrameIndex / nCountX) * stItem.FrameH; };
            if(*pSrcW){ *pSrcW = stItem.FrameW; }
            if(*pSrcH){ *pSrcW = stItem.FrameH; }

            if(*pFrameCount){ *pFrameCount = nCountX * nCountY; }

            return stItem.Texture;
        }

        SDL_Texture *Retrieve(uint8_t nSet, uint16_t nSubset, uint8_t nIndex,
                int *pSrcX, int *pSrcY, int *pSrcW, int *pSrcH, int *pFrameCount)
        {
            uint32_t nKey = ((uint32_t)(nSet) << 24)
                + (uint32_t)(nSubset << 8) + (uint32_t)(nIndex);

            return Retrieve(nKey, pSrcX, pSrcY, pSrcW, pSrcH, pFrameCount);
        }
};