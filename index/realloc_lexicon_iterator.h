/**
 * Copyright (C) 2007 Stefan Buettcher. All rights reserved.
 * This is free software with ABSOLUTELY NO WARRANTY.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA
 **/

/**
 * author: Stefan Buettcher
 * created: 2005-08-25
 * changed: 2006-05-10
 **/


#ifndef __INDEX__REALLOC_LEXICON_ITERATOR_H
#define __INDEX__REALLOC_LEXICON_ITERATOR_H


#include "realloc_lexicon.h"
#include "index_types.h"


class ReallocLexiconIterator : public IndexIterator {

private:

	/** Where do we get our data from? **/
	ReallocLexicon *dataSource;

	/** Array of term IDs, referring to terms inside the Lexicon "dataSource". **/
	int32_t *terms;

	/** Current term in "terms" array. **/
	int termPos;

	/** Where are we currently (inside the current term's posting list)? **/
	int posInCurrentTermList;

	/** How many postings are there in total? **/
	int sizeOfCurrentTermList;

	/** Number of postings we have already fetched for the current term. **/
	int postingsFromCurrentTermFetched;

	int lengthOfCurrentChunk, sizeOfCurrentChunk;

	offset lastPosting;

	PostingListSegmentHeader tempHeader;

	byte *compressed;

	offset *uncompressed;

public:

	ReallocLexiconIterator(ReallocLexicon *lexicon);

	~ReallocLexiconIterator();

	virtual int64_t getTermCount();

	virtual int64_t getListCount();

	virtual bool hasNext();

	virtual char *getNextTerm();

	virtual PostingListSegmentHeader *getNextListHeader();

	virtual byte *getNextListCompressed(int *length, int *size);

	virtual offset *getNextListUncompressed(int *length);

	virtual void skipNext();

private:

	void getNextChunk();

}; // end of class ReallocLexiconIterator


#endif

