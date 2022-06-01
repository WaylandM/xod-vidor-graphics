#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {

        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto gfx = getValue<input_GFX>(ctx);

        auto xString = getValue<input_Text>(ctx);
        int N=length(xString) + 1;
        char cString[N];
        for(int i=0;i<N;i++)
        cString[i]=0;
        dump(xString, cString);

        auto color = getValue<input_Color>(ctx);
        uint32_t color32 = gfx->Color(color.r, color.g, color.b);

        gfx->text.setCursor(
            getValue<input_X>(ctx),
            getValue<input_Y>(ctx));
        gfx->text.setAlpha(getValue<input_Alpha>(ctx));
        gfx->text.setSize(getValue<input_Size>(ctx));
        gfx->setFont(getValue<input_Font>(ctx));
        gfx->text.setColor(color32);
        gfx->println(cString);

        emitValue<output_Done>(ctx, 1);
    }
}
