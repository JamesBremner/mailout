#ifndef ATTACHMENT_H
#define ATTACHMENT_H

#include "base64.h"
#include <cstring>
#include <fstream>


	#define ATTACHMENT_API


namespace jed_utils
{
	/** @brief The Attachment class represent a file attachment in a 
	 *  message. It can be a picture, a document, a text file etc.
	 */
	class ATTACHMENT_API Attachment
	{
	public:
		/**
		 *  @brief  Construct a new Attachment. 
		 *  @param pFilename The full path of the file.
		 *  @param pName The display name of the file that will appear in 
		 *  the mail content  
		 */
		explicit Attachment(const char *pFilename, const char *pName = "");
		
		/** Destructor of the Attachment */
		~Attachment();

		/** Attachment copy constructor. */
		Attachment(const Attachment& other);
        
		/** Attachment copy assignment operator. */
		Attachment& operator=(const Attachment& other);
		
		/** Attachment move constructor. */
		Attachment(Attachment&& other) noexcept;
		
		/** Attachment move assignment operator. */
		Attachment& operator=(Attachment&& other) noexcept;
		
		/** Return the display name. */
		const char *getName() const;
		
		/** Return the file name including the path. */
		const char *getFilename() const;

		/** Return the base64 representation of the file content. */
		const char *getBase64EncodedFile() const;

		/** Return the MIME type corresponding to the file extension. */
		const char *getMimeType() const;
		
		friend class Message;
	private:
		Attachment() = default;
		char *mName;
		char *mFilename;
	};
} // namespace jed_utils

#endif
