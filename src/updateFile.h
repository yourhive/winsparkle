/*
 *  This file is part of WinSparkle (http://winsparkle.org)
 *
 *  Copyright (C) 2009-2010 Vaclav Slavik
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _updateapp_h_
#define _updateapp_h_

#include "threads.h"

#include <string>

namespace winsparkle
{

/**
    This class checks the appcast for updates.

    If an update is found, then UpdateChecker initializes the GUI thread
    and shows information about available update to the user.
 */
class UpdateFile : public Thread
{
public:
    /// Creates checker thread.
	UpdateFile(const char* filename);

protected:

protected:
    virtual void Run();
    virtual bool IsJoinable() const { return false; }

private:
	bool DownloadZipFromFeedUrl();

	void CloseAppFromFeedAppId();

	void UpdateApp();

	bool UnzipFile();

private:
	std::string		m_zipFileUrl;
	std::string		m_filename;
};

} // namespace winsparkle

#endif // _updatechecker_h_
