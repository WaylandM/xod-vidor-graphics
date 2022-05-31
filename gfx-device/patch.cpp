#pragma XOD error_raise enable
#pragma XOD require "https://github.com/vidor-libraries/VidorGraphics"
#include <VidorGraphics.h>
#include <Vidor_GFX.h>

node {
    meta {
        using Type = Vidor_GFX*;
    }

    Vidor_GFX gfx = Vidor_GFX();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        if (!FPGA->begin()) {
            raiseError(ctx);
            return;
        }

        emitValue<output_Prefs>(ctx, &gfx);
    }

}
