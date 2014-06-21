
package proguard.optimize.info;

import proguard.classfile.*;
import proguard.classfile.attribute.*;
import proguard.classfile.attribute.visitor.AttributeVisitor;
import proguard.classfile.instruction.*;
import proguard.classfile.instruction.visitor.InstructionVisitor;
import proguard.classfile.util.SimplifiedVisitor;

public class VariableUsageMarker
extends      SimplifiedVisitor
implements   AttributeVisitor,
             InstructionVisitor
{
    private boolean[] variableUsed = new boolean[ClassConstants.TYPICAL_VARIABLES_SIZE];


    /**
     * Returns whether the given variable has been marked as being used.
     */
    public boolean isVariableUsed(int variableIndex)
    {
        return variableUsed[variableIndex];
    }


    // Implementations for AttributeVisitor.

    public void visitAnyAttribute(Clazz clazz, Attribute attribute) {}


    public void visitCodeAttribute(Clazz clazz, Method method, CodeAttribute codeAttribute)
    {
        int maxLocals = codeAttribute.u2maxLocals;

        // Try to reuse the previous array.
        if (variableUsed.length < maxLocals)
        {
            variableUsed = new boolean[maxLocals];
        }
        else
        {
            for (int index = 0; index < maxLocals; index++)
            {
                variableUsed[index] = false;
            }
        }

        codeAttribute.instructionsAccept(clazz, method, this);
    }


    // Implementations for InstructionVisitor.

    public void visitAnyInstruction(Clazz clazz, Method method, CodeAttribute codeAttribute, int offset, Instruction instruction) {}


    public void visitVariableInstruction(Clazz clazz, Method method, CodeAttribute codeAttribute, int offset, VariableInstruction variableInstruction)
    {
        // Mark the variable.
        variableUsed[variableInstruction.variableIndex] = true;

        // Account for Category 2 instructions, which take up two entries.
        if (variableInstruction.isCategory2())
        {
            variableUsed[variableInstruction.variableIndex + 1] = true;
        }
    }
}