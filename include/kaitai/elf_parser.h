#include "parser/parser.h"
#include "kaitai/elf.h"
namespace veles {
namespace kaitai {
class ElfParser : public parser::Parser {
public:
    ElfParser() : parser::Parser("elf (ksy)") {}
    void parse(const dbif::ObjectHandle& blob, uint64_t start = 0,
               const dbif::ObjectHandle& parent_chunk = dbif::ObjectHandle()) override {
        try {
            auto stream = kaitai::kstream(blob, start, parent_chunk);
            auto parser = kaitai::elf::elf_t(&stream);
            parser.program_headers();
            parser.section_headers();
            parser.strings();
        } catch(std::exception) {}
    }
};

}  // namespace kaitai
}  // namespace veles
