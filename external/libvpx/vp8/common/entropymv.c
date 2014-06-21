


#include "entropymv.h"

const MV_CONTEXT vp8_mv_update_probs[2] =
{
    {{
        237,
        246,
        253, 253, 254, 254, 254, 254, 254,
        254, 254, 254, 254, 254, 250, 250, 252, 254, 254
    }},
    {{
        231,
        243,
        245, 253, 254, 254, 254, 254, 254,
        254, 254, 254, 254, 254, 251, 251, 254, 254, 254
    }}
};
const MV_CONTEXT vp8_default_mv_context[2] =
{
    {{
        /* row */
        162,                                        /* is short */
        128,                                        /* sign */
        225, 146, 172, 147, 214,  39, 156,          /* short tree */
        128, 129, 132,  75, 145, 178, 206, 239, 254, 254 /* long bits */
    }},



    {{
        /* same for column */
        164,                                        /* is short */
        128,
        204, 170, 119, 235, 140, 230, 228,
        128, 130, 130,  74, 148, 180, 203, 236, 254, 254 /* long bits */

    }}
};