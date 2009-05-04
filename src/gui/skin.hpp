#ifndef HEADER_SKIN_HPP
#define HEADER_SKIN_HPP

#include <irrlicht.h>
#include "ptr_vector.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace GUIEngine
{
    
    class Widget;
    
    /** class containing render params for the 'drawBoxFromStretchableTexture' function */
    class BoxRenderParams
    {
    public:
        int left_border, right_border, top_border, bottom_border;
        bool preserve_h_aspect_ratios;
        float hborder_out_portion, vborder_out_portion;
        bool vertical_flip;
        
        /** bitmap containing which areas to render */
        int areas;
        // possible values in areas
        static const int BODY = 1;
        static const int LEFT = 2;
        static const int RIGHT = 4;
        static const int TOP = 8;
        static const int BOTTOM = 16;
        
        BoxRenderParams();
    };
    
    class Skin : public IGUISkin
    {
        IGUISkin* m_fallback_skin;
        
        /* f : focused; d : down state */
        ITexture* m_tex_button;
        ITexture* m_tex_fbutton;
        ITexture* m_tex_spinner;
        ITexture* m_tex_fspinner;
        ITexture* m_tex_dspinner;
        ITexture* m_tex_tab;
        ITexture* m_tex_ftab;
        ITexture* m_tex_dtab;
        ITexture* m_tex_ficonhighlight;
        ITexture* m_tex_bubble;
        ITexture* m_tex_squarefocus;
        ITexture* m_tex_gaugefill;
        
        ITexture* m_tex_checkbox;
        ITexture* m_tex_fcheckbox;
        ITexture* m_tex_dcheckbox;
        ITexture* m_tex_dfcheckbox;
        
        void drawBoxFromStretchableTexture(const core::rect< s32 > &dest, ITexture* source, const BoxRenderParams& params);
        
    public:
        ITexture* m_tex_section;
        
        Skin(IGUISkin* fallback_skin);
        ~Skin();
        
        // my utility methods, to work around irrlicht's very Windows-95-like-look-enforcing skin system
        void process3DPane(IGUIElement *element, const core::rect< s32 > &rect, const bool pressed);
        void drawButton(const core::rect< s32 > &rect, const bool pressed, const bool focused);
        void drawRibbon(const core::rect< s32 > &rect, const Widget* widget, const bool pressed, bool focused);
        void drawRibbonChild(const core::rect< s32 > &rect, const Widget* widget, const bool pressed, bool focused);
        void drawSpinnerChild(const core::rect< s32 > &rect, Widget* widget, const bool pressed, bool focused);
        void drawSpinnerBody(const core::rect< s32 > &rect, const Widget* widget, const bool pressed, bool focused);
        void drawGauge(const core::rect< s32 > &rect, Widget* widget, bool focused);
        void drawGaugeFill(const core::rect< s32 > &rect, Widget* widget, bool focused);
        void drawCheckBox(const core::rect< s32 > &rect, Widget* widget, bool focused);
        
        void renderSections(ptr_vector<Widget>* within_vector=NULL);
        
        // irrlicht's callbacks
        virtual void 	draw2DRectangle (IGUIElement *element, const video::SColor &color, const core::rect< s32 > &pos, const core::rect< s32 > *clip);
        virtual void 	draw3DButtonPanePressed (IGUIElement *element, const core::rect< s32 > &rect, const core::rect< s32 > *clip);
        virtual void 	draw3DButtonPaneStandard (IGUIElement *element, const core::rect< s32 > &rect, const core::rect< s32 > *clip);
        virtual void 	draw3DMenuPane (IGUIElement *element, const core::rect< s32 > &rect, const core::rect< s32 > *clip);
        virtual void 	draw3DSunkenPane (IGUIElement *element, video::SColor bgcolor, bool flat, bool fillBackGround, const core::rect< s32 > &rect, const core::rect< s32 > *clip);
        virtual void 	draw3DTabBody (IGUIElement *element, bool border, bool background, const core::rect< s32 > &rect, const core::rect< s32 > *clip, s32 tabHeight=-1, gui::EGUI_ALIGNMENT alignment=EGUIA_UPPERLEFT);
        virtual void 	draw3DTabButton (IGUIElement *element, bool active, const core::rect< s32 > &rect, const core::rect< s32 > *clip, gui::EGUI_ALIGNMENT alignment=EGUIA_UPPERLEFT);
        virtual void 	draw3DToolBar (IGUIElement *element, const core::rect< s32 > &rect, const core::rect< s32 > *clip);
        virtual core::rect< s32 > 	draw3DWindowBackground (IGUIElement *element, bool drawTitleBar, video::SColor titleBarColor, const core::rect< s32 > &rect, const core::rect< s32 > *clip);
        virtual void 	drawIcon (IGUIElement *element, EGUI_DEFAULT_ICON icon, const core::position2di position, u32 starttime, u32 currenttime, bool loop=false, const core::rect< s32 > *clip=NULL);
        virtual video::SColor 	getColor (EGUI_DEFAULT_COLOR color) const;
        virtual const wchar_t * 	getDefaultText (EGUI_DEFAULT_TEXT text) const;
        virtual IGUIFont * 	getFont (EGUI_DEFAULT_FONT which=EGDF_DEFAULT) const ;
        virtual u32 	getIcon (EGUI_DEFAULT_ICON icon) const ;
        virtual s32 	getSize (EGUI_DEFAULT_SIZE size) const ;
        virtual IGUISpriteBank * 	getSpriteBank () const ;
        //virtual EGUI_SKIN_TYPE 	getType () const;
        virtual void 	setColor (EGUI_DEFAULT_COLOR which, video::SColor newColor);
        virtual void 	setDefaultText (EGUI_DEFAULT_TEXT which, const wchar_t *newText);
        virtual void 	setFont (IGUIFont *font, EGUI_DEFAULT_FONT which=EGDF_DEFAULT);
        virtual void 	setIcon (EGUI_DEFAULT_ICON icon, u32 index);
        virtual void 	setSize (EGUI_DEFAULT_SIZE which, s32 size);
        virtual void 	setSpriteBank (IGUISpriteBank *bank);
        
    };
}
#endif
