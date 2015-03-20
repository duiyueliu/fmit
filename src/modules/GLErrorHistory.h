// Copyright 2004 "Gilles Degottex"

// This file is part of "fmit"

// "fmit" is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// "fmit" is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



#ifndef _GLErrorHistory_h_
#define _GLErrorHistory_h_

#include <deque>
using namespace std;
#include <qgl.h>
#include <qspinbox.h>
#include <qsettings.h>
#include <qaction.h>
class QTimer;
#include <Music/Music.h>
#include "View.h"

class GLErrorHistory : public QGLWidget, public View
{
	Q_OBJECT

	virtual void mouseReleaseEvent(QMouseEvent* e){View::mouseReleaseEvent(e);}

	void drawTicksCent(int r, int ticks_size);
	void drawTextTickCent(int r, int dy);

  public:
	GLErrorHistory(QWidget* parent);

	struct Note
	{
		int ht;
		QString factor;
		float min_err;
		float max_err;
		float avg_err;
		deque<float> errors;
		void init();
		Note(int h);
		Note(int h, int num, int den);
		Note(int h, float cents);
		void addError(float err);
		QString getName() const;
	};
	deque<Note> m_notes;
	void addNote(GLErrorHistory::Note note);
	void addError(float err);

	// settings
	QAction* setting_keep;
	QAction* setting_useCents;
	QSpinBox* setting_spinScale;
	virtual void save();
	virtual void load();
	virtual void clearSettings();

  public slots:
	void initializeGL();
	void paintGL();
	void resizeGL( int w, int h );
	void keepPreviousNotes(bool keep);
};

#endif // _GLErrorHistory_h_

