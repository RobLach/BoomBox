#include "GameGUI.h"
#include "Ogre.h"
#include "CEGUI.h"
#include "OgreCEGUIRenderer.h"
#include "CEGUIXMLAttributes.h"


 GameGUI::GameGUI(Ogre::RenderWindow *extWindow, Ogre::SceneManager *extSceneMgr)
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



	//Window *w = winMgr->loadWindowLayout( "Login.layout" );
	//w->setPosition(UVector2(cegui_reldim(0.50f), cegui_reldim( 0.50f)));
    //sheet->addChildWindow(w);


		Window* guiLayout = winMgr->loadWindowLayout("ChatBox.layout");
			sheet->addChildWindow(guiLayout);


			

	//Window* guiLayout = winMgr->loadWindowLayout("ChatBox.layout");
	//		sheet->addChildWindow(guiLayout);

//	setScheme("TaharezLookSkin.scheme");


		//Window *playerList = winMgr->createWindow("DefaultGUISheet", "CEGUIDemo/PlayerLIst");

//		sheet->addChildWindow(playerList);


   // FrameWindow* wnd = (FrameWindow*)winMgr->createWindow("TaharezLook/FrameWindow", "Demo Window");

    // Here we attach the newly created FrameWindow to the previously created
    // DefaultWindow which we will be using as the root of the displayed gui.
    //sheet->addChildWindow(wnd);

    // Windows are in Relative metrics mode by default.  This means that we can
    // specify sizes and positions without having to know the exact pixel size
    // of the elements in advance.  The relative metrics mode co-ordinates are
    // relative to the parent of the window where the co-ordinates are being set.
    // This means that if 0.5f is specified as the width for a window, that window
    // will be half as its parent window.
    //
    // Here we set the FrameWindow so that it is half the size of the display,
    // and centered within the display.
    //wnd->setPosition(UVector2(cegui_reldim(0.25f), cegui_reldim( 0.25f)));
    //wnd->setSize(UVector2(cegui_reldim(0.5f), cegui_reldim( 0.5f)));

    // now we set the maximum and minum sizes for the new window.  These are
    // specified using relative co-ordinates, but the important thing to note
    // is that these settings are aways relative to the display rather than the
    // parent window.
    //
    // here we set a maximum size for the FrameWindow which is equal to the size
    // of the display, and a minimum size of one tenth of the display.
    //wnd->setMaxSize(UVector2(cegui_reldim(1.0f), cegui_reldim( 1.0f)));
    //wnd->setMinSize(UVector2(cegui_reldim(0.1f), cegui_reldim( 0.1f)));

    // As a final step in the initialisation of our sample window, we set the window's
    // text to "Hello World!", so that this text will appear as the caption in the
    // FrameWindow's titlebar.
    //wnd->setText("Hello World!");

	  // load the drive icons imageset
    //ImagesetManager::getSingleton().createImageset("DriveIcons.imageset");

	Listbox * listBox = static_cast<Listbox*>(winMgr->createWindow("TaharezLook/Listbox", "Listbox1"));
sheet->addChildWindow(listBox);

listBox->setPosition(UVector2(cegui_reldim(0.7f), cegui_reldim(0.1f)));
listBox->setSize(UVector2(cegui_reldim(0.4f), cegui_reldim(0.4f)));
//listBox->addWindowToDrawList(*wnd);			
ListboxTextItem * listBoxItem = new ListboxTextItem("Speed Boost", 1);
listBoxItem->setSelectionBrushImage("TaharezLook", "MultiListSelectionBrush");
listBox->addItem(listBoxItem);

listBoxItem = new ListboxTextItem("Our second item.", 2);
listBoxItem->setSelectionBrushImage("TaharezLook", "MultiListSelectionBrush");
listBox->addItem(listBoxItem);


//Editbox * editBox = static_cast<Editbox*>(winMgr->createWindow("TaharezLook/Editbox", "Editbox1"));
//sheet->addChildWindow(editBox);
//
//editBox->setPosition(UVector2(cegui_reldim(0.f), cegui_reldim(0.8f)));
//editBox->setSize(UVector2(cegui_reldim(0.4f), cegui_reldim(0.1f)));
//editBox->setText("Edit me!");


Checkbox * checkBox = static_cast<Checkbox*>(winMgr->createWindow("TaharezLook/Checkbox", "Checkbox1"));
sheet->addChildWindow(checkBox);
checkBox->setPosition(UVector2(cegui_reldim(0.7f), cegui_reldim(0.8f)));
checkBox->setSize(UVector2(cegui_reldim(0.4f), cegui_reldim(0.1f)));

// A question where people can only answer yes or no (true or false)
checkBox->setText("Do You Wanna Join Team 1?");






	
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

void GameGUI::setScheme(char *scheme)
{
    CEGUI::SchemeManager::getSingleton().loadScheme((CEGUI::utf8*)scheme);
}

void GameGUI::setMouseArrow(char *scheme, char *type)
{
    mSystem->setDefaultMouseCursor((CEGUI::utf8*)scheme, (CEGUI::utf8*)type);
    CEGUI::MouseCursor::getSingleton().setImage(CEGUI::System::getSingleton().getDefaultMouseCursor());
}

void GameGUI::setFont(char *font)
{
    mSystem->setDefaultFont((CEGUI::utf8*)font);
}

void GameGUI::setSheet(char *sheet)
{
    CEGUI::Window* guiSheet = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"ogregui.layout");   
    mSystem->setGUISheet(guiSheet);
}

void GameGUI::setImageset(char * imageset)
{
    CEGUI::ImagesetManager::getSingletonPtr()->createImageset(imageset);
}

bool GameGUI::keyPressed(const CEGUI::EventArgs &e)
{
    const CEGUI::KeyEventArgs& key = static_cast<const CEGUI::KeyEventArgs&>(e);
    if (key.scancode == CEGUI::Key::Tab)
    {
        setSheet("WordInv.layout");
    }
    return true;
}

bool GameGUI::keyUp(const CEGUI::EventArgs &e)
{
    const CEGUI::KeyEventArgs& key = static_cast<const CEGUI::KeyEventArgs&>(e);
    if (key.scancode == CEGUI::Key::Tab)
    {
        setSheet("blank.layout");
    }
    return true;
}

bool GameGUI::buttonClicked(const CEGUI::EventArgs &e)
{
    return true;
}

bool GameGUI::mouseMove(const CEGUI::EventArgs &e)
{
    return true;
}

bool GameGUI::onTextChanged(const CEGUI::EventArgs &e)
{
	CEGUI::WindowManager * winMgr = CEGUI::WindowManager::getSingletonPtr();
	CEGUI::MultiLineEditbox * multiLineEditbox = static_cast<CEGUI::MultiLineEditbox*>(winMgr->getWindow("MultiEditbox1"));
	CEGUI::Window * textWindow = winMgr->getWindow("StaticText1");

	textWindow->setText(multiLineEditbox->getText());
	return true;
}







