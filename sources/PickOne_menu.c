/*  menu.c																				This contains all the menu code.																						Michael Bishop - August 21 1996														Nick Thompson	(c)1994-96 Apple computer Inc., All Rights Reserved								*//* --------------------------------------------------------------------** Includes*/#include	<StandardFile.h>#include	<Devices.h>#include	"PickOne_menu.h"#include	"PickOne_utility.h"#include	"PickOne_window.h"#include	"PickOne_document.h"#include	"PickOne_main.h"#include	"QD3DAcceleration.h"/* --------------------------------------------------------------------** Global Variables*//* --------------------------------------------------------------------** Local Functions*//*	--------------------------------------------------------------------**	Menu_Adjust**	Update the menus to reflect the current status of the App*/void Menu_Adjust( void ) {	DocumentHdl			theDocument;	MenuHandle			theMenu;	WindowPtr			theWindow = FrontWindow();		if (theWindow != NULL) {			theDocument = Window_GetDocument(theWindow);		if(theDocument != NULL)	{						/*	Renderer Menu	*/			{				long	theVendorID, theEngineID;								Document_GetRendererPreferences(theDocument, &theVendorID, &theEngineID);								theMenu = GetMenuHandle(mRenderer);				if (theVendorID == kQAVendor_BestChoice)				{					CheckItem(theMenu, iBest, true);				}				else				{					CheckItem(theMenu, iBest, false);				}				if (theEngineID == kQAEngine_AppleHW)					CheckItem(theMenu, iHardware, true);				else					CheckItem(theMenu, iHardware, false);				if (theEngineID == kQAEngine_AppleSW)					CheckItem(theMenu, iSoftware, true);				else					CheckItem(theMenu, iSoftware, false);			}		}	}}/*	--------------------------------------------------------------------**	Menu_HandleCommand**	Finds out what was selected and does something about it.*/void Menu_HandleCommand(long menuResult){	short				menuID;	short				menuItem;	Str255				daName;	MenuHandle			theMenu;		DocumentHdl			theDocument;	short				numTypes = 1 ;	SFTypeList			myTypes = { '3DMF', 0 } ;		WindowPtr			theWindow = FrontWindow() ;				theDocument = Window_GetDocument(theWindow);	menuID = Utility_HiWrd(menuResult);	menuItem = Utility_LoWrd(menuResult);		switch ( menuID ) {		/*  */		/* --------------------------------------------------------------------------	 */		/*  */		case mApple:			switch ( menuItem ) {				case iAbout:					Main_DoAbout() ;						break ;												default:					GetMenuItemText(GetMenuHandle(mApple), menuItem, daName);					(void) OpenDeskAcc(daName);					break;			}			break;		/* --------------------------------------------------------------------------	 */		case mFile:			switch ( menuItem ) {							case iNew:					Document_New() ;					break ;								case iOpen:					Document_Open(Document_New()) ;					break ;				case iSave:						Document_Save( Window_GetDocument(theWindow) ) ;					break ;								case iSaveAs:					break;												case iClose:					Document_Dispose( Window_GetDocument(theWindow) ) ;					break ;									case iQuit:					gQuitFlag = true ;					break;			}			break;								/* --------------------------------------------------------------------------	 */		case mEdit:			switch(menuItem)			{				case iCut:					break;				case iCopy:					break;				case iPaste:					break;				case iClear:					break;				default:					break;			}			break; 		/* --------------------------------------------------------------------------	 */		case mRenderer:		if (theWindow != NULL)		{			long	theVendorID, theEngineID;			Document_GetRendererPreferences(theDocument, &theVendorID, &theEngineID);							theMenu = GetMenuHandle(mRenderer);						switch(menuItem)				{					case iSoftware:						theEngineID = kQAEngine_AppleSW;						break;					case iHardware:						theEngineID = kQAEngine_AppleHW;						break;					case iBest:					if ( theVendorID == kQAVendor_Apple)						theVendorID = kQAVendor_BestChoice;					else						theVendorID = kQAVendor_Apple;						break;					default:						break;				}			Document_SetRendererPreferences(theDocument, theVendorID, theEngineID);			HLock((Handle)theDocument);			Document_Draw(*theDocument);			HUnlock((Handle)theDocument);		}		break; 	}	HiliteMenu(0);		/*  Unhighlight whatever MenuSelect or MenuKey hilited */}