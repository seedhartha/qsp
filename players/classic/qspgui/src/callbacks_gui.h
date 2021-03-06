// Copyright (C) 2005-2010 Valeriy Argunov (nporep AT mail DOT ru)
/*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#ifndef CALLBACKS_GUI_H
	#define CALLBACKS_GUI_H

	#include <map>
	#include "frame.h"
	#include "msgdlg.h"
	#include "inputdlg.h"
	#include "fmod.h"

	typedef struct
	{
		FMOD_CHANNEL *Channel;
		FMOD_SOUND *Sound;
		int Volume;

		void Free() const
		{
			FMOD_Sound_Release(Sound);
		}
	} QSPSound;

	typedef std::map<wxString, QSPSound> QSPSounds;

	class QSPCallBacks
	{
	public:
		// Methods
		static void Init(QSPFrame *frame);
		static void DeInit();
		static void SetOverallVolume(float coeff);

		// CallBacks
		static void RefreshInt(QSP_BOOL isRedraw);
		static void SetTimer(int msecs);
		static void SetInputStrText(const QSP_CHAR *text);
		static QSP_BOOL IsPlay(const QSP_CHAR *file);
		static void CloseFile(const QSP_CHAR *file);
		static void PlayFile(const QSP_CHAR *file, int volume);
		static void ShowPane(int type, QSP_BOOL isShow);
		static void Sleep(int msecs);
		static int GetMSCount();
		static void Msg(const QSP_CHAR *str);
		static void DeleteMenu();
		static void AddMenuItem(const QSP_CHAR *name, const QSP_CHAR *imgPath);
		static void ShowMenu();
		static void Input(const QSP_CHAR *text, QSP_CHAR *buffer, int maxLen);
		static void ShowImage(const QSP_CHAR *file);
		static void OpenGameStatus(const QSP_CHAR *file);
		static void SaveGameStatus(const QSP_CHAR *file);
	private:
		// Internal methods
		static void UpdateGamePath();
		static bool SetVolume(const QSP_CHAR *file, int volume);
		static void UpdateSounds();

		// Fields
		static wxString m_gamePath;
		static QSPFrame *m_frame;
		static bool m_isHtml;
		static FMOD_SYSTEM *m_sys;
		static QSPSounds m_sounds;
		static float m_volumeCoeff;
	};

#endif
