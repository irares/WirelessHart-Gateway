/*
* Copyright (C) 2013 Nivis LLC.
* Email:   opensource@nivis.com
* Website: http://www.nivis.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
* 
* Redistribution and use in source and binary forms must retain this
* copyright notice.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "C020_ReadLongTag.h"

uint8_t Compose_C020_ReadLongTag_Req(C020_ReadLongTag_Req* request,
			ComposerContext* context, BinaryStream* toStream)
{
	context->cmdId = CMDID_C020_ReadLongTag;

	return RCS_N00_Success;
}

uint8_t Parse_C020_ReadLongTag_Req(C020_ReadLongTag_Req* request,
			ParserContext* context, BinaryStream* fromStream)
{
	return RCS_N00_Success; //success
}

uint8_t Compose_C020_ReadLongTag_Resp(C020_ReadLongTag_Resp* response,
		ComposerContext* context, BinaryStream* toStream)
{
	context->cmdId = CMDID_C020_ReadLongTag;

	STREAM_WRITE_LATIN(toStream, response->longTag, sizeof(response->longTag));

	return RCS_N00_Success;
}

uint8_t Parse_C020_ReadLongTag_Resp(C020_ReadLongTag_Resp* response,
		ParserContext* context, BinaryStream* fromStream)
{

	#if defined(_DEBUG)
// 		if (fromStream->remainingBytes < C020_RespSize)
// 			return RCS_E05_TooFewDataBytesReceived;
	#endif

	STREAM_READ_LATIN(fromStream, &response->longTag, sizeof(response->longTag));

	return RCS_N00_Success; //success
}

