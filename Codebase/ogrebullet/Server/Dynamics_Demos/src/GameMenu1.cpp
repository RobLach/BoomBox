#include "GameMenu1.h"
#include "Ogre.h"
#include "CEGUI.h"
#include "OgreCEGUIRenderer.h"
#include "CEGUIXMLAttributes.h"


GameMenu1::GameMenu1(Ogre::RenderWindow *extWindow, Ogre::SceneManager *extSceneMgr)
{
   mRenderer = new CEGUI::OgreCEGUIRenderer(extWindow, Ogre::RENDER_QUEUE_OVERLAY, false, 3000, extSceneMgr);
    mSystem = new CEGUI::System(mRenderer);
    winMgr = CEGUI::WindowManager::getSingletonPtr();

//	setScheme("WindowsLook.scheme");
   setScheme("TaharezLookSkin.scheme");
   setMouseArrow("TaharezLook", "MouseArrow");
    setFont("BlueHighway-12");

	using namespace CEGUI;
	try {
        Window *sheet = winMgr->createWindow("DefaultGUISheet", "CEGUIDemo/Sheet");
		

        Window *quit = winMgr->createWindow("TaharezLook/Button", "CEGUIDemo/QuitButton");
		
        quit->setText("Quit");
        quit->setSize(CEGUI::UVector2(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));

        sheet->addChildWindow(quit);
        mSystem->setGUISheet(sheet);

	//	setScheme("WindowsLookSkin.scheme");



	Window *w = winMgr->loadWindowLayout( "Login.layout" );
	//w->setPosition(UVector2(cegui_reldim(0.50f), cegui_reldim( 0.50f)));
    sheet->addChildWindow(w);


	//Window* guiLayout = winMgr->loadWindowLayout("ChatBox.layout");
	//		sheet->addChildWindow(guiLayout);

//	setScheme("TaharezLookSkin.scheme");


		//Window *playerList = winMgr->createWindow("DefaultGUISheet", "CEGUIDemo/PlayerLIst");

//		sheet->addChildWindow(playerList);


 





	

	
		 mouseEnabled = true;
	}
	catch(Exception &e)
		{
			#if defined( __WIN32__ ) || defined( _WIN32 )
			//	MessageBox(NULL, e.getMessage().c_str(), "Error initializing the demo", MB_OK | MB_ICONERROR | MB_TASKMODAL);
			#else
				std::cerr << "Error initializing the demo:" << e.getMessage().c_str() << "\n";
			#endif
		}

	

    //setSheet("Demo8.layout");

    // subscribe to events
   // root = winMgr->getWindow("Root");
   // root->subscribeEvent(CEGUI::DefaultWindow::EventKeyDown, CEGUI::Event::Subscriber(&GameGUI::keyPressed, this));
   // root->subscribeEvent(CEGUI::DefaultWindow::EventKeyUp, CEGUI::Event::Subscriber(&GameGUI::keyUp, this));


}

void GameMenu1::setScheme(char *scheme)
{
    CEGUI::SchemeManager::getSingleton().loadScheme((CEGUI::utf8*)scheme);
}

void GameMenu1::setMouseArrow(char *scheme, char *type)
{
    mSystem->setDefaultMouseCursor((CEGUI::utf8*)scheme, (CEGUI::utf8*)type);
    CEGUI::MouseCursor::getSingleton().setImage(CEGUI::System::getSingleton().getDefaultMouseCursor());
}

void GameMenu1::setFont(char *font)
{
    mSystem->setDefaultFont((CEGUI::utf8*)font);
}

void GameMenu1::setSheet(char *sheet)
{
    CEGUI::Window* guiSheet = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"ogregui.layout");   
    mSystem->setGUISheet(guiSheet);
}

void GameMenu1::setImageset(char * imageset)
{
    CEGUI::ImagesetManager::getSingletonPtr()->createImageset(imageset);
}

bool GameMenu1::keyPressed(const CEGUI::EventArgs &e)
{
    const CEGUI::KeyEventArgs& key = static_cast<const CEGUI::KeyEventArgs&>(e);
    if (key.scancode == CEGUI::Key::Tab)
    {
        setSheet("WordInv.layout");
    }
    return true;
}

bool GameMenu1::keyUp(const CEGUI::EventArgs &e)
{
    const CEGUI::KeyEventArgs& key = static_cast<const CEGUI::KeyEventArgs&>(e);
    if (key.scancode == CEGUI::Key::Tab)
    {
        setSheet("blank.layout");
    }
    return true;
}

bool GameMenu1::buttonClicked(const CEGUI::EventArgs &e)
{
    return true;
}

bool GameMenu1::mouseMove(const CEGUI::EventArgs &e)
{
    return true;
}

bool GameMenu1::onTextChanged(const CEGUI::EventArgs &e)
{
	CEGUI::WindowManager * winMgr = CEGUI::WindowManager::getSingletonPtr();
	CEGUI::MultiLineEditbox * multiLineEditbox = static_cast<CEGUI::MultiLineEditbox*>(winMgr->getWindow("MultiEditbox1"));
	CEGUI::Window * textWindow = winMgr->getWindow("StaticText1");

	textWindow->setText(multiLineEditbox->getText());
	return true;
}



