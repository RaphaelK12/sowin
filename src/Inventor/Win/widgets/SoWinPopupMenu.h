/**************************************************************************\
 *
 *  Copyright (C) 1998-2000 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

//  $Id$

#ifndef SOWIN_POPUPMENU_H
#define SOWIN_POPUPMENU_H

#include <Inventor/Win/SoWinBasic.h>

#include <Inventor/Win/widgets/SoAnyPopupMenu.h>

// *************************************************************************

struct MenuRecord;
struct ItemRecord;

class SOWIN_DLL_EXPORT SoWinPopupMenu : public SoAnyPopupMenu
{
  typedef SoAnyPopupMenu inherited;

public:
  SoWinPopupMenu( void );
  ~SoWinPopupMenu( void );

  int NewMenu( char * name, int menuid = -1 );
  int GetMenu( char * name );
  void SetMenuTitle( int id, char * title );
  char * GetMenuTitle( int id );

  int NewMenuItem( char * name, int itemid = -1 );
  int GetMenuItem( char * name );
  void SetMenuItemTitle( int itemid, char * title );
  char * GetMenuItemTitle( int itemid );
  void SetMenuItemEnabled( int itemid, SbBool enabled );
  SbBool GetMenuItemEnabled( int itemid );
  SbBool GetMenuItemMarked( int itemid );

  virtual void SetMenuItemMarked( int itemid, SbBool marked );

  void AddMenu( int menuid, int submenuid, int pos = -1 );
  void AddMenuItem( int menuid, int itemid, int pos = -1 );
  void AddSeparator( int menuid, int pos = -1 );
  void RemoveMenu( int menuid );
  void RemoveMenuItem( int itemid );

  void PopUp( HWND inside, int x, int y );

  void itemActivation( int itemid );    // call this on WM_COMMAND

protected:
  void _setMenuItemMarked( int itemid, SbBool marked );
  MenuRecord * getMenuRecord( int menuid );
  ItemRecord * getItemRecord( int itemid );
  MenuRecord * createMenuRecord( char * name );
  ItemRecord * createItemRecord( char * name );

private:
  SbPList * menus;
  SbPList * items;

};  // class SoWinPopupMenu

// *************************************************************************

#endif // ! SOWIN_POPUPMENU_H
