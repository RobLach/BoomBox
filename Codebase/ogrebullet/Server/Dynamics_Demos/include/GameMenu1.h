


#include "CEGUI.h"
#include "OgreCEGUIRenderer.h"

class GameMenu1
{
public:

    GameMenu1();

    ~GameMenu1();

    GameMenu1(Ogre::RenderWindow * extWindow, Ogre::SceneManager * extSceneMgr);

    void setMouseArrow(char * scheme, char * type);

    void setFont(char * font);

    void setScheme(char * scheme);

    void setSheet(char * sheet);

    void setImageset(char * imageset);

protected:

    CEGUI::OgreCEGUIRenderer *mRenderer; // the cegui renderer object
    CEGUI::System *mSystem; // the cegui system object
    bool mouseEnabled;
    CEGUI::Window * root;
    CEGUI::WindowManager * winMgr;

    bool keyPressed(const CEGUI::EventArgs &e);

    bool keyUp(const CEGUI::EventArgs &e);

    bool buttonClicked(const CEGUI::EventArgs &e);
	bool onTextChanged(const CEGUI::EventArgs &e);

    bool mouseMove(const CEGUI::EventArgs &e);

};