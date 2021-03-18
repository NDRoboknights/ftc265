// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package com.roboknights4348.lib.wpiutil.src.main.java.edu.wpi.first.wpiutil;

import java.util.concurrent.atomic.AtomicBoolean;

public final class WPIUtilJNI
{

    public static long now(){return System.nanoTime();}

    public static class Helper {
        private static final AtomicBoolean extractOnStaticLoad = new AtomicBoolean(true);

        public static boolean getExtractOnStaticLoad() {
            return extractOnStaticLoad.get();
        }

        public static void setExtractOnStaticLoad(boolean load) {
            extractOnStaticLoad.set(load);
        }
    }
}
