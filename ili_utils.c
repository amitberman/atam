#include <asm/desc.h>

void my_store_idt(struct desc_ptr *idtr) {
// <STUDENT FILL> - HINT: USE INLINE ASSEMBLY
asm("sidt %0;"
    :
    :"m"(idtr)
    :
);

// </STUDENT FILL> GET THE IDTR TO HE MEMORY
}

void my_load_idt(struct desc_ptr *idtr) {
// <STUDENT FILL> - HINT: USE INLINE ASSEMBLY
asm("ldtr %0;"
    :
    :"m"(idtr)
    :
);
// <STUDENT FILL> LOADING THE NEW IDT TABLE IN TO THE IDTR
}

void my_set_gate_offset(gate_desc *gate, unsigned long addr) {
// <STUDENT FILL> - HINT: NO NEED FOR INLINE ASSEMBLY
    unsigned long tmp = addr << 49;
    tmp = addr >> 49;
    gate -> offset_low;
    tmp = addr >> 16;
    tmp = addr << 49;
    gate -> offset_middle;
    tmp = addr >> 32;
    gate -> offset_high;
// </STUDENT FILL> SET THE ADDRESS OF THE HANDLER FUNCTION
}

unsigned long my_get_gate_offset(gate_desc *gate) {
// <STUDENT FILL> - HINT: NO NEED FOR INLINE ASSEMBLY
    unsigned long tmp = gate -> offset_high;
    tmp = tmp << 16;
    tmp += gate -> offset_middle;
    tmp = tmp << 16;
    tmp+= gate -> offset_low;
    return tmp;
// </STUDENT FILL> GET THE ADDRESS OF THE HANDLER FUNCTION
}
