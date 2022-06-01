#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {

        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gfx = getValue<input_GFX>(ctx);
        auto color = getValue<input_Color>(ctx);
        uint32_t color32 = gfx->Color(color.r, color.g, color.b);
        gfx->drawLine(
            getValue<input_X0>(ctx),
            getValue<input_Y0>(ctx),
            getValue<input_X1>(ctx),
            getValue<input_Y1>(ctx),
            color32,
            getValue<input_Alpha>(ctx));
        emitValue<output_Done>(ctx, 1);
    }
}
