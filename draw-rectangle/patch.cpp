#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {

        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gfx = getValue<input_GFX>(ctx);
        auto color = getValue<input_Color>(ctx);
        uint32_t color32 = gfx->Color(color.r, color.g, color.b);
        if (getValue<input_Fill){
            gfx->fillRectangle(
            getValue<input_X>(ctx),
            getValue<input_Y>(ctx),
            getValue<input_W>(ctx),
            getValue<input_H>(ctx),
            color32,
            getValue<input_Alpha>(ctx));
        } else {
            gfx->drawRectangle(
            getValue<input_X>(ctx),
            getValue<input_Y>(ctx),
            getValue<input_W>(ctx),
            getValue<input_H>(ctx),
            color32,
            getValue<input_Alpha>(ctx)
            );
        }
        emitValue<output_Done>(ctx, 1);
    }
}
