 /**************************************************************************
 *
 *  This file is part of the Coin SoWin GUI binding library.
 *  Copyright (C) 2000 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation.  See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin SoWin for applications not compatible with the
 *  LGPL, please contact SIM to aquire a Professional Edition License.
 *
 *  Systems in Motion, Prof Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
 **************************************************************************/

#include <Win32API.h>
#include <stdio.h>
#include <assert.h>

void
Win32::showLastErr(void)
{
  LPTSTR buffer;

  DWORD lasterr = GetLastError();

  BOOL result =
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		  FORMAT_MESSAGE_FROM_SYSTEM |
		  FORMAT_MESSAGE_IGNORE_INSERTS,
		  NULL,
		  lasterr,
		  0,
		  (LPTSTR)&buffer,
		  0,
		  NULL);

  if (result) {
    (void)printf("\n*** GetLastError()==%d (\"%s\")\n", lasterr, buffer);
    (void)LocalFree(buffer);
  }
}

void
Win32::MoveWindow(HWND hWnd,      // handle to window
                  int X,          // horizontal position
                  int Y,          // vertical position
                  int nWidth,     // width
                  int nHeight,    // height
                  BOOL bRepaint   // repaint flag
                  )
{
  BOOL r = ::MoveWindow( hWnd, X, Y, nWidth, nHeight, bRepaint);
  if (!r) { Win32::showLastErr(); }
  assert( r && "MoveWindow() failed -- investigate");
}

void
Win32::EnableWindow(HWND hWnd,     // handle to window
		    BOOL bEnable   // flag for enabling or disabling input
		    )
{
  BOOL enabled = ::IsWindowEnabled(hWnd);
  if (enabled && bEnable) { return; }
  if (!enabled && !bEnable) { return; }

  BOOL r = ::EnableWindow( hWnd, bEnable );
  BOOL fail = (!r && bEnable) || (r && !bEnable);
  if (fail) { Win32::showLastErr(); }
  assert( !fail && "EnableWindow() failed -- investigate" );
}
 

void
Win32::SwapBuffers(HDC hdc  // device context whose buffers get swapped
		   )
{
  BOOL r = ::SwapBuffers(hdc);
  if (!r) { Win32::showLastErr(); }
  assert( r && "SwapBuffers() failed -- investigate");
}
