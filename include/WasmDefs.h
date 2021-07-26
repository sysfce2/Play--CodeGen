#pragma once

namespace Wasm
{
	enum
	{
		BINARY_MAGIC = 0x6D736100,
		BINARY_VERSION = 0x01,
	};

	enum SECTION_ID
	{
		SECTION_ID_TYPE = 0x01,
		SECTION_ID_IMPORT = 0x02,
		SECTION_ID_FUNCTION = 0x03,
		SECTION_ID_EXPORT = 0x07,
		SECTION_ID_CODE = 0x0A,
	};

	enum IMPORT_EXPORT_TYPE
	{
		IMPORT_EXPORT_TYPE_FUNCTION = 0x00,
		IMPORT_EXPORT_TYPE_MEMORY = 0x02,
	};

#pragma pack(push, 1)
	struct SECTION_HEADER
	{
		uint8 code;
		uint8 size;
	};
#pragma pack(pop)

	enum TYPE_CODE
	{
		TYPE_I32 = 0x7F,
	};

	enum INST_CODE
	{
		INST_END = 0x0B,
		INST_I32_ADD = 0x6A,
		INST_I32_SHL = 0x74,
		INST_I32_SHR_S = 0x75,
		INST_I32_SHR_U = 0x76
	};
}
