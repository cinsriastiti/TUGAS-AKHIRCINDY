#include <cstdint>
#include <algorithm>

// ============================================================
// Auto-generated Extra Trees Model
// Features : x[0]=N, x[1]=P, x[2]=K, x[3]=EC, x[4]=pH, x[5]=Temp, x[6]=Hum
// Classes  : 0=Bawang Daun, 1=Bawang Merah, 2=Cabai, 3=Parsley, 4=Selada , 5=Tomat, 6=Zucchini
// Trees    : 10
// ============================================================

// --- Tree 1 of 10 ---
static int tree_0(float *x) {
if (x[0] <= 19.4988f) {  // N <= 19.4988
    if (x[1] <= 14.0299f) {  // P <= 14.0299
        if (x[0] <= 16.2527f) {  // N <= 16.2527
            if (x[5] <= 28.7764f) {  // Temp <= 28.7764
                if (x[5] <= 26.7183f) {  // Temp <= 26.7183
                    return 2; // Cabai
                } else {  // Temp > 26.7183
                    if (x[1] <= 13.7017f) {  // P <= 13.7017
                        if (x[4] <= 4.9259f) {  // pH <= 4.9259
                            if (x[4] <= 4.6522f) {  // pH <= 4.6522
                                return 1; // Bawang Merah
                            } else {  // pH > 4.6522
                                return 1; // Bawang Merah
                            }
                        } else {  // pH > 4.9259
                            if (x[0] <= 13.1575f) {  // N <= 13.1575
                                if (x[5] <= 28.0305f) {  // Temp <= 28.0305
                                    return 0; // Bawang Daun
                                } else {  // Temp > 28.0305
                                    if (x[4] <= 5.6527f) {  // pH <= 5.6527
                                        if (x[3] <= 139.0237f) {  // EC <= 139.0237
                                            return 0; // Bawang Daun
                                        } else {  // EC > 139.0237
                                            return 0; // Bawang Daun
                                        }
                                    } else {  // pH > 5.6527
                                        return 0; // Bawang Daun
                                    }
                                }
                            } else {  // N > 13.1575
                                if (x[6] <= 89.9200f) {  // Hum <= 89.9200
                                    return 1; // Bawang Merah
                                } else {  // Hum > 89.9200
                                    return 0; // Bawang Daun
                                }
                            }
                        }
                    } else {  // P > 13.7017
                        if (x[6] <= 65.0338f) {  // Hum <= 65.0338
                            return 5; // Tomat
                        } else {  // Hum > 65.0338
                            if (x[2] <= 16.0656f) {  // K <= 16.0656
                                if (x[6] <= 78.2235f) {  // Hum <= 78.2235
                                    return 5; // Tomat
                                } else {  // Hum > 78.2235
                                    if (x[0] <= 7.0707f) {  // N <= 7.0707
                                        return 5; // Tomat
                                    } else {  // N > 7.0707
                                        return 1; // Bawang Merah
                                    }
                                }
                            } else {  // K > 16.0656
                                return 1; // Bawang Merah
                            }
                        }
                    }
                }
            } else {  // Temp > 28.7764
                if (x[5] <= 30.0174f) {  // Temp <= 30.0174
                    if (x[3] <= 138.4139f) {  // EC <= 138.4139
                        if (x[2] <= 6.3440f) {  // K <= 6.3440
                            return 5; // Tomat
                        } else {  // K > 6.3440
                            if (x[1] <= 13.1454f) {  // P <= 13.1454
                                return 0; // Bawang Daun
                            } else {  // P > 13.1454
                                if (x[5] <= 29.1001f) {  // Temp <= 29.1001
                                    return 1; // Bawang Merah
                                } else {  // Temp > 29.1001
                                    if (x[5] <= 29.2065f) {  // Temp <= 29.2065
                                        return 1; // Bawang Merah
                                    } else {  // Temp > 29.2065
                                        return 5; // Tomat
                                    }
                                }
                            }
                        }
                    } else {  // EC > 138.4139
                        return 0; // Bawang Daun
                    }
                } else {  // Temp > 30.0174
                    return 0; // Bawang Daun
                }
            }
        } else {  // N > 16.2527
            return 1; // Bawang Merah
        }
    } else {  // P > 14.0299
        if (x[3] <= 29.7545f) {  // EC <= 29.7545
            return 1; // Bawang Merah
        } else {  // EC > 29.7545
            if (x[4] <= 5.2364f) {  // pH <= 5.2364
                if (x[2] <= 0.0084f) {  // K <= 0.0084
                    if (x[5] <= 24.3619f) {  // Temp <= 24.3619
                        return 3; // Parsley
                    } else {  // Temp > 24.3619
                        if (x[1] <= 15.9979f) {  // P <= 15.9979
                            if (x[4] <= 4.9233f) {  // pH <= 4.9233
                                if (x[0] <= 4.1392f) {  // N <= 4.1392
                                    if (x[5] <= 27.6793f) {  // Temp <= 27.6793
                                        if (x[3] <= 45.2872f) {  // EC <= 45.2872
                                            return 3; // Parsley
                                        } else {  // EC > 45.2872
                                            return 2; // Cabai
                                        }
                                    } else {  // Temp > 27.6793
                                        return 1; // Bawang Merah
                                    }
                                } else {  // N > 4.1392
                                    return 1; // Bawang Merah
                                }
                            } else {  // pH > 4.9233
                                if (x[5] <= 28.4714f) {  // Temp <= 28.4714
                                    return 3; // Parsley
                                } else {  // Temp > 28.4714
                                    return 1; // Bawang Merah
                                }
                            }
                        } else {  // P > 15.9979
                            if (x[4] <= 5.0542f) {  // pH <= 5.0542
                                return 3; // Parsley
                            } else {  // pH > 5.0542
                                return 3; // Parsley
                            }
                        }
                    }
                } else {  // K > 0.0084
                    return 2; // Cabai
                }
            } else {  // pH > 5.2364
                if (x[5] <= 25.2726f) {  // Temp <= 25.2726
                    if (x[5] <= 24.1423f) {  // Temp <= 24.1423
                        return 3; // Parsley
                    } else {  // Temp > 24.1423
                        if (x[4] <= 5.4189f) {  // pH <= 5.4189
                            return 3; // Parsley
                        } else {  // pH > 5.4189
                            if (x[3] <= 43.2170f) {  // EC <= 43.2170
                                return 3; // Parsley
                            } else {  // EC > 43.2170
                                return 2; // Cabai
                            }
                        }
                    }
                } else {  // Temp > 25.2726
                    if (x[1] <= 15.2507f) {  // P <= 15.2507
                        if (x[5] <= 26.9699f) {  // Temp <= 26.9699
                            return 3; // Parsley
                        } else {  // Temp > 26.9699
                            return 1; // Bawang Merah
                        }
                    } else {  // P > 15.2507
                        if (x[6] <= 84.7435f) {  // Hum <= 84.7435
                            return 3; // Parsley
                        } else {  // Hum > 84.7435
                            return 1; // Bawang Merah
                        }
                    }
                }
            }
        }
    }
} else {  // N > 19.4988
    if (x[6] <= 85.1315f) {  // Hum <= 85.1315
        if (x[3] <= 567.4458f) {  // EC <= 567.4458
            return 6; // Zucchini
        } else {  // EC > 567.4458
            return 4; // Selada 
        }
    } else {  // Hum > 85.1315
        return 6; // Zucchini
    }
}
}

// --- Tree 2 of 10 ---
static int tree_1(float *x) {
if (x[5] <= 32.4845f) {  // Temp <= 32.4845
    if (x[5] <= 28.5601f) {  // Temp <= 28.5601
        if (x[5] <= 26.5038f) {  // Temp <= 26.5038
            if (x[3] <= 183.8283f) {  // EC <= 183.8283
                if (x[2] <= 7.3836f) {  // K <= 7.3836
                    if (x[1] <= 14.8176f) {  // P <= 14.8176
                        return 2; // Cabai
                    } else {  // P > 14.8176
                        if (x[1] <= 15.9817f) {  // P <= 15.9817
                            if (x[3] <= 48.9364f) {  // EC <= 48.9364
                                if (x[0] <= 3.9229f) {  // N <= 3.9229
                                    return 3; // Parsley
                                } else {  // N > 3.9229
                                    return 3; // Parsley
                                }
                            } else {  // EC > 48.9364
                                if (x[6] <= 84.9142f) {  // Hum <= 84.9142
                                    return 3; // Parsley
                                } else {  // Hum > 84.9142
                                    return 2; // Cabai
                                }
                            }
                        } else {  // P > 15.9817
                            return 3; // Parsley
                        }
                    }
                } else {  // K > 7.3836
                    return 2; // Cabai
                }
            } else {  // EC > 183.8283
                if (x[4] <= 5.0229f) {  // pH <= 5.0229
                    return 2; // Cabai
                } else {  // pH > 5.0229
                    return 2; // Cabai
                }
            }
        } else {  // Temp > 26.5038
            if (x[2] <= 59.6682f) {  // K <= 59.6682
                if (x[0] <= 9.7346f) {  // N <= 9.7346
                    if (x[4] <= 3.1976f) {  // pH <= 3.1976
                        return 5; // Tomat
                    } else {  // pH > 3.1976
                        if (x[2] <= 2.1418f) {  // K <= 2.1418
                            if (x[2] <= 1.3367f) {  // K <= 1.3367
                                if (x[0] <= 6.3185f) {  // N <= 6.3185
                                    if (x[3] <= 66.7319f) {  // EC <= 66.7319
                                        return 1; // Bawang Merah
                                    } else {  // EC > 66.7319
                                        if (x[6] <= 70.9820f) {  // Hum <= 70.9820
                                            return 5; // Tomat
                                        } else {  // Hum > 70.9820
                                            if (x[3] <= 81.0709f) {  // EC <= 81.0709
                                                return 1; // Bawang Merah
                                            } else {  // EC > 81.0709
                                                return 1; // Bawang Merah
                                            }
                                        }
                                    }
                                } else {  // N > 6.3185
                                    return 5; // Tomat
                                }
                            } else {  // K > 1.3367
                                if (x[5] <= 28.1332f) {  // Temp <= 28.1332
                                    return 5; // Tomat
                                } else {  // Temp > 28.1332
                                    return 1; // Bawang Merah
                                }
                            }
                        } else {  // K > 2.1418
                            return 5; // Tomat
                        }
                    }
                } else {  // N > 9.7346
                    if (x[0] <= 13.9352f) {  // N <= 13.9352
                        if (x[4] <= 5.7029f) {  // pH <= 5.7029
                            if (x[0] <= 12.3966f) {  // N <= 12.3966
                                return 0; // Bawang Daun
                            } else {  // N > 12.3966
                                return 0; // Bawang Daun
                            }
                        } else {  // pH > 5.7029
                            return 0; // Bawang Daun
                        }
                    } else {  // N > 13.9352
                        if (x[3] <= 273.8656f) {  // EC <= 273.8656
                            if (x[2] <= 23.5403f) {  // K <= 23.5403
                                if (x[5] <= 27.5124f) {  // Temp <= 27.5124
                                    return 1; // Bawang Merah
                                } else {  // Temp > 27.5124
                                    if (x[2] <= 16.0956f) {  // K <= 16.0956
                                        return 0; // Bawang Daun
                                    } else {  // K > 16.0956
                                        if (x[6] <= 81.7812f) {  // Hum <= 81.7812
                                            return 1; // Bawang Merah
                                        } else {  // Hum > 81.7812
                                            return 0; // Bawang Daun
                                        }
                                    }
                                }
                            } else {  // K > 23.5403
                                return 1; // Bawang Merah
                            }
                        } else {  // EC > 273.8656
                            return 6; // Zucchini
                        }
                    }
                }
            } else {  // K > 59.6682
                return 6; // Zucchini
            }
        }
    } else {  // Temp > 28.5601
        if (x[2] <= 12.3901f) {  // K <= 12.3901
            if (x[2] <= 3.1741f) {  // K <= 3.1741
                if (x[1] <= 14.9717f) {  // P <= 14.9717
                    if (x[0] <= 6.6334f) {  // N <= 6.6334
                        return 1; // Bawang Merah
                    } else {  // N > 6.6334
                        if (x[6] <= 85.3853f) {  // Hum <= 85.3853
                            return 5; // Tomat
                        } else {  // Hum > 85.3853
                            return 1; // Bawang Merah
                        }
                    }
                } else {  // P > 14.9717
                    return 1; // Bawang Merah
                }
            } else {  // K > 3.1741
                if (x[5] <= 29.6015f) {  // Temp <= 29.6015
                    if (x[1] <= 13.3432f) {  // P <= 13.3432
                        return 0; // Bawang Daun
                    } else {  // P > 13.3432
                        if (x[4] <= 4.5668f) {  // pH <= 4.5668
                            return 5; // Tomat
                        } else {  // pH > 4.5668
                            if (x[5] <= 28.7008f) {  // Temp <= 28.7008
                                return 1; // Bawang Merah
                            } else {  // Temp > 28.7008
                                if (x[2] <= 6.2727f) {  // K <= 6.2727
                                    return 1; // Bawang Merah
                                } else {  // K > 6.2727
                                    if (x[5] <= 29.1832f) {  // Temp <= 29.1832
                                        return 1; // Bawang Merah
                                    } else {  // Temp > 29.1832
                                        return 1; // Bawang Merah
                                    }
                                }
                            }
                        }
                    }
                } else {  // Temp > 29.6015
                    return 0; // Bawang Daun
                }
            }
        } else {  // K > 12.3901
            if (x[2] <= 37.5388f) {  // K <= 37.5388
                if (x[1] <= 13.6268f) {  // P <= 13.6268
                    if (x[4] <= 5.3801f) {  // pH <= 5.3801
                        return 0; // Bawang Daun
                    } else {  // pH > 5.3801
                        if (x[2] <= 13.8901f) {  // K <= 13.8901
                            return 0; // Bawang Daun
                        } else {  // K > 13.8901
                            if (x[4] <= 5.8365f) {  // pH <= 5.8365
                                return 0; // Bawang Daun
                            } else {  // pH > 5.8365
                                return 0; // Bawang Daun
                            }
                        }
                    }
                } else {  // P > 13.6268
                    return 1; // Bawang Merah
                }
            } else {  // K > 37.5388
                if (x[3] <= 564.5196f) {  // EC <= 564.5196
                    return 6; // Zucchini
                } else {  // EC > 564.5196
                    return 4; // Selada 
                }
            }
        }
    }
} else {  // Temp > 32.4845
    if (x[5] <= 34.1130f) {  // Temp <= 34.1130
        if (x[4] <= 3.3979f) {  // pH <= 3.3979
            return 4; // Selada 
        } else {  // pH > 3.3979
            if (x[6] <= 73.3545f) {  // Hum <= 73.3545
                if (x[5] <= 32.6356f) {  // Temp <= 32.6356
                    return 4; // Selada 
                } else {  // Temp > 32.6356
                    return 4; // Selada 
                }
            } else {  // Hum > 73.3545
                return 4; // Selada 
            }
        }
    } else {  // Temp > 34.1130
        return 4; // Selada 
    }
}
}

// --- Tree 3 of 10 ---
static int tree_2(float *x) {
if (x[5] <= 32.4788f) {  // Temp <= 32.4788
    if (x[2] <= 21.6156f) {  // K <= 21.6156
        if (x[3] <= 60.0873f) {  // EC <= 60.0873
            if (x[2] <= 0.0061f) {  // K <= 0.0061
                if (x[1] <= 15.9780f) {  // P <= 15.9780
                    if (x[0] <= 3.4986f) {  // N <= 3.4986
                        return 3; // Parsley
                    } else {  // N > 3.4986
                        if (x[6] <= 90.5780f) {  // Hum <= 90.5780
                            if (x[6] <= 82.3921f) {  // Hum <= 82.3921
                                return 3; // Parsley
                            } else {  // Hum > 82.3921
                                if (x[5] <= 26.2021f) {  // Temp <= 26.2021
                                    if (x[3] <= 48.9251f) {  // EC <= 48.9251
                                        return 3; // Parsley
                                    } else {  // EC > 48.9251
                                        return 2; // Cabai
                                    }
                                } else {  // Temp > 26.2021
                                    return 1; // Bawang Merah
                                }
                            }
                        } else {  // Hum > 90.5780
                            return 3; // Parsley
                        }
                    }
                } else {  // P > 15.9780
                    if (x[3] <= 31.0946f) {  // EC <= 31.0946
                        return 1; // Bawang Merah
                    } else {  // EC > 31.0946
                        if (x[6] <= 83.9245f) {  // Hum <= 83.9245
                            return 3; // Parsley
                        } else {  // Hum > 83.9245
                            return 3; // Parsley
                        }
                    }
                }
            } else {  // K > 0.0061
                return 2; // Cabai
            }
        } else {  // EC > 60.0873
            if (x[6] <= 73.0540f) {  // Hum <= 73.0540
                if (x[0] <= 7.9071f) {  // N <= 7.9071
                    return 5; // Tomat
                } else {  // N > 7.9071
                    if (x[2] <= 5.8275f) {  // K <= 5.8275
                        return 5; // Tomat
                    } else {  // K > 5.8275
                        if (x[1] <= 13.0597f) {  // P <= 13.0597
                            if (x[2] <= 18.5963f) {  // K <= 18.5963
                                return 0; // Bawang Daun
                            } else {  // K > 18.5963
                                return 1; // Bawang Merah
                            }
                        } else {  // P > 13.0597
                            return 5; // Tomat
                        }
                    }
                }
            } else {  // Hum > 73.0540
                if (x[4] <= 4.7083f) {  // pH <= 4.7083
                    if (x[4] <= 4.1697f) {  // pH <= 4.1697
                        return 5; // Tomat
                    } else {  // pH > 4.1697
                        if (x[5] <= 27.8225f) {  // Temp <= 27.8225
                            return 2; // Cabai
                        } else {  // Temp > 27.8225
                            if (x[5] <= 29.2294f) {  // Temp <= 29.2294
                                return 1; // Bawang Merah
                            } else {  // Temp > 29.2294
                                return 5; // Tomat
                            }
                        }
                    }
                } else {  // pH > 4.7083
                    if (x[0] <= 8.7064f) {  // N <= 8.7064
                        if (x[5] <= 27.7433f) {  // Temp <= 27.7433
                            return 2; // Cabai
                        } else {  // Temp > 27.7433
                            if (x[0] <= 6.5383f) {  // N <= 6.5383
                                if (x[3] <= 79.8245f) {  // EC <= 79.8245
                                    return 1; // Bawang Merah
                                } else {  // EC > 79.8245
                                    if (x[6] <= 85.4683f) {  // Hum <= 85.4683
                                        return 1; // Bawang Merah
                                    } else {  // Hum > 85.4683
                                        return 1; // Bawang Merah
                                    }
                                }
                            } else {  // N > 6.5383
                                return 1; // Bawang Merah
                            }
                        }
                    } else {  // N > 8.7064
                        if (x[1] <= 13.4859f) {  // P <= 13.4859
                            if (x[3] <= 170.4462f) {  // EC <= 170.4462
                                if (x[0] <= 10.6270f) {  // N <= 10.6270
                                    if (x[6] <= 83.7376f) {  // Hum <= 83.7376
                                        return 2; // Cabai
                                    } else {  // Hum > 83.7376
                                        if (x[5] <= 26.0400f) {  // Temp <= 26.0400
                                            return 2; // Cabai
                                        } else {  // Temp > 26.0400
                                            return 0; // Bawang Daun
                                        }
                                    }
                                } else {  // N > 10.6270
                                    if (x[0] <= 13.6248f) {  // N <= 13.6248
                                        if (x[4] <= 5.8343f) {  // pH <= 5.8343
                                            if (x[4] <= 5.2054f) {  // pH <= 5.2054
                                                if (x[4] <= 5.0701f) {  // pH <= 5.0701
                                                    return 0; // Bawang Daun
                                                } else {  // pH > 5.0701
                                                    return 0; // Bawang Daun
                                                }
                                            } else {  // pH > 5.2054
                                                if (x[2] <= 14.9945f) {  // K <= 14.9945
                                                    return 0; // Bawang Daun
                                                } else {  // K > 14.9945
                                                    if (x[3] <= 166.4427f) {  // EC <= 166.4427
                                                        return 0; // Bawang Daun
                                                    } else {  // EC > 166.4427
                                                        return 0; // Bawang Daun
                                                    }
                                                }
                                            }
                                        } else {  // pH > 5.8343
                                            if (x[3] <= 157.5695f) {  // EC <= 157.5695
                                                return 0; // Bawang Daun
                                            } else {  // EC > 157.5695
                                                return 1; // Bawang Merah
                                            }
                                        }
                                    } else {  // N > 13.6248
                                        if (x[5] <= 29.4190f) {  // Temp <= 29.4190
                                            if (x[6] <= 86.5640f) {  // Hum <= 86.5640
                                                return 2; // Cabai
                                            } else {  // Hum > 86.5640
                                                return 0; // Bawang Daun
                                            }
                                        } else {  // Temp > 29.4190
                                            return 0; // Bawang Daun
                                        }
                                    }
                                }
                            } else {  // EC > 170.4462
                                if (x[5] <= 26.8910f) {  // Temp <= 26.8910
                                    return 2; // Cabai
                                } else {  // Temp > 26.8910
                                    return 1; // Bawang Merah
                                }
                            }
                        } else {  // P > 13.4859
                            if (x[5] <= 28.9589f) {  // Temp <= 28.9589
                                if (x[4] <= 5.2061f) {  // pH <= 5.2061
                                    return 1; // Bawang Merah
                                } else {  // pH > 5.2061
                                    return 2; // Cabai
                                }
                            } else {  // Temp > 28.9589
                                if (x[4] <= 5.1814f) {  // pH <= 5.1814
                                    return 1; // Bawang Merah
                                } else {  // pH > 5.1814
                                    return 1; // Bawang Merah
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {  // K > 21.6156
        if (x[5] <= 25.0938f) {  // Temp <= 25.0938
            return 2; // Cabai
        } else {  // Temp > 25.0938
            if (x[1] <= 17.2128f) {  // P <= 17.2128
                if (x[0] <= 17.3162f) {  // N <= 17.3162
                    if (x[4] <= 4.1698f) {  // pH <= 4.1698
                        return 1; // Bawang Merah
                    } else {  // pH > 4.1698
                        if (x[3] <= 207.6912f) {  // EC <= 207.6912
                            return 1; // Bawang Merah
                        } else {  // EC > 207.6912
                            return 1; // Bawang Merah
                        }
                    }
                } else {  // N > 17.3162
                    return 2; // Cabai
                }
            } else {  // P > 17.2128
                if (x[0] <= 45.8425f) {  // N <= 45.8425
                    if (x[2] <= 109.0699f) {  // K <= 109.0699
                        return 6; // Zucchini
                    } else {  // K > 109.0699
                        return 4; // Selada 
                    }
                } else {  // N > 45.8425
                    return 4; // Selada 
                }
            }
        }
    }
} else {  // Temp > 32.4788
    if (x[4] <= 4.0296f) {  // pH <= 4.0296
        return 4; // Selada 
    } else {  // pH > 4.0296
        if (x[4] <= 4.4295f) {  // pH <= 4.4295
            return 4; // Selada 
        } else {  // pH > 4.4295
            return 4; // Selada 
        }
    }
}
}

// --- Tree 4 of 10 ---
static int tree_3(float *x) {
if (x[1] <= 39.9136f) {  // P <= 39.9136
    if (x[5] <= 25.9705f) {  // Temp <= 25.9705
        if (x[1] <= 14.9129f) {  // P <= 14.9129
            return 2; // Cabai
        } else {  // P > 14.9129
            if (x[2] <= 0.8030f) {  // K <= 0.8030
                if (x[5] <= 25.3047f) {  // Temp <= 25.3047
                    if (x[3] <= 48.5901f) {  // EC <= 48.5901
                        return 3; // Parsley
                    } else {  // EC > 48.5901
                        if (x[6] <= 84.9670f) {  // Hum <= 84.9670
                            return 3; // Parsley
                        } else {  // Hum > 84.9670
                            return 2; // Cabai
                        }
                    }
                } else {  // Temp > 25.3047
                    return 3; // Parsley
                }
            } else {  // K > 0.8030
                return 2; // Cabai
            }
        }
    } else {  // Temp > 25.9705
        if (x[3] <= 275.4081f) {  // EC <= 275.4081
            if (x[0] <= 12.2443f) {  // N <= 12.2443
                if (x[2] <= 0.0099f) {  // K <= 0.0099
                    if (x[4] <= 5.6112f) {  // pH <= 5.6112
                        if (x[4] <= 5.5189f) {  // pH <= 5.5189
                            return 1; // Bawang Merah
                        } else {  // pH > 5.5189
                            return 3; // Parsley
                        }
                    } else {  // pH > 5.6112
                        if (x[0] <= 3.4493f) {  // N <= 3.4493
                            return 3; // Parsley
                        } else {  // N > 3.4493
                            if (x[6] <= 65.8092f) {  // Hum <= 65.8092
                                return 5; // Tomat
                            } else {  // Hum > 65.8092
                                return 1; // Bawang Merah
                            }
                        }
                    }
                } else {  // K > 0.0099
                    if (x[6] <= 91.9487f) {  // Hum <= 91.9487
                        if (x[6] <= 82.3212f) {  // Hum <= 82.3212
                            if (x[2] <= 6.8363f) {  // K <= 6.8363
                                if (x[0] <= 7.8093f) {  // N <= 7.8093
                                    if (x[5] <= 29.2418f) {  // Temp <= 29.2418
                                        if (x[6] <= 67.1838f) {  // Hum <= 67.1838
                                            return 5; // Tomat
                                        } else {  // Hum > 67.1838
                                            return 1; // Bawang Merah
                                        }
                                    } else {  // Temp > 29.2418
                                        return 5; // Tomat
                                    }
                                } else {  // N > 7.8093
                                    return 5; // Tomat
                                }
                            } else {  // K > 6.8363
                                if (x[1] <= 13.0776f) {  // P <= 13.0776
                                    return 0; // Bawang Daun
                                } else {  // P > 13.0776
                                    return 5; // Tomat
                                }
                            }
                        } else {  // Hum > 82.3212
                            if (x[6] <= 86.0298f) {  // Hum <= 86.0298
                                if (x[5] <= 30.4202f) {  // Temp <= 30.4202
                                    if (x[0] <= 8.9161f) {  // N <= 8.9161
                                        return 1; // Bawang Merah
                                    } else {  // N > 8.9161
                                        return 5; // Tomat
                                    }
                                } else {  // Temp > 30.4202
                                    return 0; // Bawang Daun
                                }
                            } else {  // Hum > 86.0298
                                if (x[6] <= 86.4540f) {  // Hum <= 86.4540
                                    if (x[6] <= 86.2235f) {  // Hum <= 86.2235
                                        return 5; // Tomat
                                    } else {  // Hum > 86.2235
                                        return 5; // Tomat
                                    }
                                } else {  // Hum > 86.4540
                                    return 1; // Bawang Merah
                                }
                            }
                        }
                    } else {  // Hum > 91.9487
                        return 0; // Bawang Daun
                    }
                }
            } else {  // N > 12.2443
                if (x[4] <= 5.1132f) {  // pH <= 5.1132
                    if (x[0] <= 14.9910f) {  // N <= 14.9910
                        if (x[5] <= 28.3548f) {  // Temp <= 28.3548
                            if (x[3] <= 171.9040f) {  // EC <= 171.9040
                                return 0; // Bawang Daun
                            } else {  // EC > 171.9040
                                return 1; // Bawang Merah
                            }
                        } else {  // Temp > 28.3548
                            return 0; // Bawang Daun
                        }
                    } else {  // N > 14.9910
                        return 1; // Bawang Merah
                    }
                } else {  // pH > 5.1132
                    if (x[3] <= 197.2663f) {  // EC <= 197.2663
                        if (x[5] <= 29.9430f) {  // Temp <= 29.9430
                            return 0; // Bawang Daun
                        } else {  // Temp > 29.9430
                            return 0; // Bawang Daun
                        }
                    } else {  // EC > 197.2663
                        return 1; // Bawang Merah
                    }
                }
            }
        } else {  // EC > 275.4081
            return 6; // Zucchini
        }
    }
} else {  // P > 39.9136
    return 4; // Selada 
}
}

// --- Tree 5 of 10 ---
static int tree_4(float *x) {
if (x[1] <= 18.1875f) {  // P <= 18.1875
    if (x[1] <= 14.6561f) {  // P <= 14.6561
        if (x[5] <= 29.3789f) {  // Temp <= 29.3789
            if (x[2] <= 7.1744f) {  // K <= 7.1744
                if (x[5] <= 27.1517f) {  // Temp <= 27.1517
                    return 2; // Cabai
                } else {  // Temp > 27.1517
                    if (x[4] <= 4.7365f) {  // pH <= 4.7365
                        if (x[0] <= 7.9290f) {  // N <= 7.9290
                            if (x[6] <= 85.8927f) {  // Hum <= 85.8927
                                return 1; // Bawang Merah
                            } else {  // Hum > 85.8927
                                return 5; // Tomat
                            }
                        } else {  // N > 7.9290
                            return 5; // Tomat
                        }
                    } else {  // pH > 4.7365
                        if (x[6] <= 77.6144f) {  // Hum <= 77.6144
                            return 5; // Tomat
                        } else {  // Hum > 77.6144
                            if (x[3] <= 100.7565f) {  // EC <= 100.7565
                                if (x[6] <= 84.8755f) {  // Hum <= 84.8755
                                    return 1; // Bawang Merah
                                } else {  // Hum > 84.8755
                                    if (x[5] <= 28.7475f) {  // Temp <= 28.7475
                                        return 1; // Bawang Merah
                                    } else {  // Temp > 28.7475
                                        return 1; // Bawang Merah
                                    }
                                }
                            } else {  // EC > 100.7565
                                return 1; // Bawang Merah
                            }
                        }
                    }
                }
            } else {  // K > 7.1744
                if (x[1] <= 13.4584f) {  // P <= 13.4584
                    if (x[2] <= 13.2058f) {  // K <= 13.2058
                        return 0; // Bawang Daun
                    } else {  // K > 13.2058
                        if (x[4] <= 4.8497f) {  // pH <= 4.8497
                            if (x[3] <= 178.4418f) {  // EC <= 178.4418
                                if (x[2] <= 17.8530f) {  // K <= 17.8530
                                    return 2; // Cabai
                                } else {  // K > 17.8530
                                    return 1; // Bawang Merah
                                }
                            } else {  // EC > 178.4418
                                return 1; // Bawang Merah
                            }
                        } else {  // pH > 4.8497
                            if (x[2] <= 15.7184f) {  // K <= 15.7184
                                return 0; // Bawang Daun
                            } else {  // K > 15.7184
                                if (x[3] <= 167.9776f) {  // EC <= 167.9776
                                    if (x[3] <= 166.9922f) {  // EC <= 166.9922
                                        return 0; // Bawang Daun
                                    } else {  // EC > 166.9922
                                        return 0; // Bawang Daun
                                    }
                                } else {  // EC > 167.9776
                                    if (x[4] <= 5.0850f) {  // pH <= 5.0850
                                        if (x[2] <= 16.8429f) {  // K <= 16.8429
                                            return 0; // Bawang Daun
                                        } else {  // K > 16.8429
                                            return 1; // Bawang Merah
                                        }
                                    } else {  // pH > 5.0850
                                        return 0; // Bawang Daun
                                    }
                                }
                            }
                        }
                    }
                } else {  // P > 13.4584
                    if (x[5] <= 26.5945f) {  // Temp <= 26.5945
                        if (x[6] <= 86.8558f) {  // Hum <= 86.8558
                            if (x[0] <= 17.5275f) {  // N <= 17.5275
                                if (x[3] <= 219.0608f) {  // EC <= 219.0608
                                    return 2; // Cabai
                                } else {  // EC > 219.0608
                                    return 2; // Cabai
                                }
                            } else {  // N > 17.5275
                                return 2; // Cabai
                            }
                        } else {  // Hum > 86.8558
                            return 2; // Cabai
                        }
                    } else {  // Temp > 26.5945
                        return 1; // Bawang Merah
                    }
                }
            }
        } else {  // Temp > 29.3789
            if (x[2] <= 22.2760f) {  // K <= 22.2760
                if (x[3] <= 124.4182f) {  // EC <= 124.4182
                    return 0; // Bawang Daun
                } else {  // EC > 124.4182
                    return 0; // Bawang Daun
                }
            } else {  // K > 22.2760
                return 1; // Bawang Merah
            }
        }
    } else {  // P > 14.6561
        if (x[5] <= 30.2475f) {  // Temp <= 30.2475
            if (x[1] <= 15.1505f) {  // P <= 15.1505
                if (x[3] <= 56.4931f) {  // EC <= 56.4931
                    if (x[3] <= 44.6924f) {  // EC <= 44.6924
                        if (x[4] <= 5.2280f) {  // pH <= 5.2280
                            return 3; // Parsley
                        } else {  // pH > 5.2280
                            return 3; // Parsley
                        }
                    } else {  // EC > 44.6924
                        if (x[6] <= 83.1603f) {  // Hum <= 83.1603
                            return 3; // Parsley
                        } else {  // Hum > 83.1603
                            if (x[4] <= 4.2307f) {  // pH <= 4.2307
                                return 2; // Cabai
                            } else {  // pH > 4.2307
                                if (x[5] <= 25.5936f) {  // Temp <= 25.5936
                                    if (x[2] <= 0.5994f) {  // K <= 0.5994
                                        return 3; // Parsley
                                    } else {  // K > 0.5994
                                        return 2; // Cabai
                                    }
                                } else {  // Temp > 25.5936
                                    return 1; // Bawang Merah
                                }
                            }
                        }
                    }
                } else {  // EC > 56.4931
                    return 1; // Bawang Merah
                }
            } else {  // P > 15.1505
                if (x[5] <= 28.8847f) {  // Temp <= 28.8847
                    if (x[6] <= 78.8935f) {  // Hum <= 78.8935
                        return 3; // Parsley
                    } else {  // Hum > 78.8935
                        if (x[5] <= 25.8435f) {  // Temp <= 25.8435
                            return 3; // Parsley
                        } else {  // Temp > 25.8435
                            if (x[3] <= 33.5674f) {  // EC <= 33.5674
                                return 3; // Parsley
                            } else {  // EC > 33.5674
                                return 3; // Parsley
                            }
                        }
                    }
                } else {  // Temp > 28.8847
                    return 1; // Bawang Merah
                }
            }
        } else {  // Temp > 30.2475
            return 1; // Bawang Merah
        }
    }
} else {  // P > 18.1875
    if (x[1] <= 22.4639f) {  // P <= 22.4639
        return 6; // Zucchini
    } else {  // P > 22.4639
        if (x[3] <= 544.8944f) {  // EC <= 544.8944
            return 6; // Zucchini
        } else {  // EC > 544.8944
            return 4; // Selada 
        }
    }
}
}

// --- Tree 6 of 10 ---
static int tree_5(float *x) {
if (x[0] <= 24.4019f) {  // N <= 24.4019
    if (x[5] <= 27.7545f) {  // Temp <= 27.7545
        if (x[1] <= 15.2244f) {  // P <= 15.2244
            if (x[3] <= 48.1392f) {  // EC <= 48.1392
                if (x[4] <= 5.1382f) {  // pH <= 5.1382
                    if (x[6] <= 91.4760f) {  // Hum <= 91.4760
                        if (x[2] <= 0.5861f) {  // K <= 0.5861
                            return 3; // Parsley
                        } else {  // K > 0.5861
                            return 2; // Cabai
                        }
                    } else {  // Hum > 91.4760
                        return 3; // Parsley
                    }
                } else {  // pH > 5.1382
                    if (x[0] <= 3.2054f) {  // N <= 3.2054
                        return 3; // Parsley
                    } else {  // N > 3.2054
                        return 3; // Parsley
                    }
                }
            } else {  // EC > 48.1392
                if (x[6] <= 85.1266f) {  // Hum <= 85.1266
                    if (x[6] <= 68.1286f) {  // Hum <= 68.1286
                        return 5; // Tomat
                    } else {  // Hum > 68.1286
                        if (x[5] <= 25.4407f) {  // Temp <= 25.4407
                            if (x[2] <= 10.2630f) {  // K <= 10.2630
                                if (x[2] <= 1.3284f) {  // K <= 1.3284
                                    return 3; // Parsley
                                } else {  // K > 1.3284
                                    return 2; // Cabai
                                }
                            } else {  // K > 10.2630
                                return 2; // Cabai
                            }
                        } else {  // Temp > 25.4407
                            return 1; // Bawang Merah
                        }
                    }
                } else {  // Hum > 85.1266
                    if (x[5] <= 24.9030f) {  // Temp <= 24.9030
                        return 2; // Cabai
                    } else {  // Temp > 24.9030
                        if (x[0] <= 9.0117f) {  // N <= 9.0117
                            return 2; // Cabai
                        } else {  // N > 9.0117
                            return 0; // Bawang Daun
                        }
                    }
                }
            }
        } else {  // P > 15.2244
            return 3; // Parsley
        }
    } else {  // Temp > 27.7545
        if (x[2] <= 7.0017f) {  // K <= 7.0017
            if (x[1] <= 14.3405f) {  // P <= 14.3405
                if (x[6] <= 69.0176f) {  // Hum <= 69.0176
                    return 5; // Tomat
                } else {  // Hum > 69.0176
                    if (x[5] <= 28.8223f) {  // Temp <= 28.8223
                        if (x[6] <= 76.5378f) {  // Hum <= 76.5378
                            return 5; // Tomat
                        } else {  // Hum > 76.5378
                            if (x[6] <= 82.0696f) {  // Hum <= 82.0696
                                return 1; // Bawang Merah
                            } else {  // Hum > 82.0696
                                if (x[4] <= 4.6646f) {  // pH <= 4.6646
                                    return 5; // Tomat
                                } else {  // pH > 4.6646
                                    if (x[2] <= 1.3683f) {  // K <= 1.3683
                                        return 1; // Bawang Merah
                                    } else {  // K > 1.3683
                                        return 1; // Bawang Merah
                                    }
                                }
                            }
                        }
                    } else {  // Temp > 28.8223
                        if (x[2] <= 3.0146f) {  // K <= 3.0146
                            return 1; // Bawang Merah
                        } else {  // K > 3.0146
                            return 5; // Tomat
                        }
                    }
                }
            } else {  // P > 14.3405
                return 1; // Bawang Merah
            }
        } else {  // K > 7.0017
            if (x[4] <= 3.8818f) {  // pH <= 3.8818
                return 1; // Bawang Merah
            } else {  // pH > 3.8818
                if (x[6] <= 82.9034f) {  // Hum <= 82.9034
                    if (x[3] <= 137.0871f) {  // EC <= 137.0871
                        return 0; // Bawang Daun
                    } else {  // EC > 137.0871
                        if (x[2] <= 16.0624f) {  // K <= 16.0624
                            if (x[4] <= 5.6293f) {  // pH <= 5.6293
                                if (x[2] <= 15.7922f) {  // K <= 15.7922
                                    return 0; // Bawang Daun
                                } else {  // K > 15.7922
                                    if (x[0] <= 13.7441f) {  // N <= 13.7441
                                        return 0; // Bawang Daun
                                    } else {  // N > 13.7441
                                        return 0; // Bawang Daun
                                    }
                                }
                            } else {  // pH > 5.6293
                                if (x[6] <= 74.1852f) {  // Hum <= 74.1852
                                    return 0; // Bawang Daun
                                } else {  // Hum > 74.1852
                                    return 0; // Bawang Daun
                                }
                            }
                        } else {  // K > 16.0624
                            return 1; // Bawang Merah
                        }
                    }
                } else {  // Hum > 82.9034
                    if (x[5] <= 29.3923f) {  // Temp <= 29.3923
                        if (x[5] <= 28.0220f) {  // Temp <= 28.0220
                            return 0; // Bawang Daun
                        } else {  // Temp > 28.0220
                            if (x[5] <= 28.4569f) {  // Temp <= 28.4569
                                if (x[5] <= 28.3430f) {  // Temp <= 28.3430
                                    return 0; // Bawang Daun
                                } else {  // Temp > 28.3430
                                    return 0; // Bawang Daun
                                }
                            } else {  // Temp > 28.4569
                                return 0; // Bawang Daun
                            }
                        }
                    } else {  // Temp > 29.3923
                        return 0; // Bawang Daun
                    }
                }
            }
        }
    }
} else {  // N > 24.4019
    if (x[3] <= 398.2414f) {  // EC <= 398.2414
        return 6; // Zucchini
    } else {  // EC > 398.2414
        return 4; // Selada 
    }
}
}

// --- Tree 7 of 10 ---
static int tree_6(float *x) {
if (x[5] <= 29.3825f) {  // Temp <= 29.3825
    if (x[1] <= 21.4429f) {  // P <= 21.4429
        if (x[1] <= 16.3820f) {  // P <= 16.3820
            if (x[3] <= 56.1165f) {  // EC <= 56.1165
                if (x[2] <= 0.8679f) {  // K <= 0.8679
                    if (x[5] <= 24.4633f) {  // Temp <= 24.4633
                        return 3; // Parsley
                    } else {  // Temp > 24.4633
                        if (x[5] <= 28.2892f) {  // Temp <= 28.2892
                            if (x[6] <= 85.4516f) {  // Hum <= 85.4516
                                return 3; // Parsley
                            } else {  // Hum > 85.4516
                                return 3; // Parsley
                            }
                        } else {  // Temp > 28.2892
                            return 1; // Bawang Merah
                        }
                    }
                } else {  // K > 0.8679
                    return 2; // Cabai
                }
            } else {  // EC > 56.1165
                if (x[5] <= 25.4791f) {  // Temp <= 25.4791
                    return 2; // Cabai
                } else {  // Temp > 25.4791
                    if (x[6] <= 70.9657f) {  // Hum <= 70.9657
                        return 5; // Tomat
                    } else {  // Hum > 70.9657
                        if (x[3] <= 194.8230f) {  // EC <= 194.8230
                            if (x[6] <= 75.8913f) {  // Hum <= 75.8913
                                if (x[6] <= 72.0162f) {  // Hum <= 72.0162
                                    return 0; // Bawang Daun
                                } else {  // Hum > 72.0162
                                    if (x[0] <= 11.7204f) {  // N <= 11.7204
                                        return 0; // Bawang Daun
                                    } else {  // N > 11.7204
                                        return 1; // Bawang Merah
                                    }
                                }
                            } else {  // Hum > 75.8913
                                if (x[2] <= 13.2524f) {  // K <= 13.2524
                                    if (x[6] <= 84.0826f) {  // Hum <= 84.0826
                                        return 1; // Bawang Merah
                                    } else {  // Hum > 84.0826
                                        if (x[2] <= 8.2881f) {  // K <= 8.2881
                                            if (x[6] <= 85.5821f) {  // Hum <= 85.5821
                                                if (x[4] <= 4.6974f) {  // pH <= 4.6974
                                                    return 5; // Tomat
                                                } else {  // pH > 4.6974
                                                    return 1; // Bawang Merah
                                                }
                                            } else {  // Hum > 85.5821
                                                if (x[6] <= 89.3459f) {  // Hum <= 89.3459
                                                    if (x[6] <= 86.2188f) {  // Hum <= 86.2188
                                                        if (x[0] <= 8.1473f) {  // N <= 8.1473
                                                            return 1; // Bawang Merah
                                                        } else {  // N > 8.1473
                                                            return 5; // Tomat
                                                        }
                                                    } else {  // Hum > 86.2188
                                                        if (x[3] <= 96.9656f) {  // EC <= 96.9656
                                                            if (x[6] <= 87.2735f) {  // Hum <= 87.2735
                                                                if (x[6] <= 86.7557f) {  // Hum <= 86.7557
                                                                    if (x[2] <= 1.4370f) {  // K <= 1.4370
                                                                        return 5; // Tomat
                                                                    } else {  // K > 1.4370
                                                                        return 1; // Bawang Merah
                                                                    }
                                                                } else {  // Hum > 86.7557
                                                                    return 5; // Tomat
                                                                }
                                                            } else {  // Hum > 87.2735
                                                                return 5; // Tomat
                                                            }
                                                        } else {  // EC > 96.9656
                                                            return 1; // Bawang Merah
                                                        }
                                                    }
                                                } else {  // Hum > 89.3459
                                                    return 2; // Cabai
                                                }
                                            }
                                        } else {  // K > 8.2881
                                            return 0; // Bawang Daun
                                        }
                                    }
                                } else {  // K > 13.2524
                                    return 0; // Bawang Daun
                                }
                            }
                        } else {  // EC > 194.8230
                            return 1; // Bawang Merah
                        }
                    }
                }
            }
        } else {  // P > 16.3820
            return 6; // Zucchini
        }
    } else {  // P > 21.4429
        return 6; // Zucchini
    }
} else {  // Temp > 29.3825
    if (x[2] <= 72.8914f) {  // K <= 72.8914
        if (x[0] <= 9.8437f) {  // N <= 9.8437
            if (x[4] <= 4.8674f) {  // pH <= 4.8674
                return 1; // Bawang Merah
            } else {  // pH > 4.8674
                if (x[3] <= 73.3260f) {  // EC <= 73.3260
                    return 1; // Bawang Merah
                } else {  // EC > 73.3260
                    return 1; // Bawang Merah
                }
            }
        } else {  // N > 9.8437
            if (x[2] <= 22.2039f) {  // K <= 22.2039
                return 0; // Bawang Daun
            } else {  // K > 22.2039
                if (x[1] <= 18.4716f) {  // P <= 18.4716
                    return 1; // Bawang Merah
                } else {  // P > 18.4716
                    return 6; // Zucchini
                }
            }
        }
    } else {  // K > 72.8914
        return 4; // Selada 
    }
}
}

// --- Tree 8 of 10 ---
static int tree_7(float *x) {
if (x[0] <= 42.3298f) {  // N <= 42.3298
    if (x[6] <= 93.3893f) {  // Hum <= 93.3893
        if (x[3] <= 201.4307f) {  // EC <= 201.4307
            if (x[5] <= 23.9377f) {  // Temp <= 23.9377
                return 3; // Parsley
            } else {  // Temp > 23.9377
                if (x[1] <= 13.1928f) {  // P <= 13.1928
                    if (x[6] <= 76.5410f) {  // Hum <= 76.5410
                        if (x[0] <= 11.3182f) {  // N <= 11.3182
                            return 0; // Bawang Daun
                        } else {  // N > 11.3182
                            if (x[5] <= 30.8302f) {  // Temp <= 30.8302
                                if (x[6] <= 71.7040f) {  // Hum <= 71.7040
                                    return 0; // Bawang Daun
                                } else {  // Hum > 71.7040
                                    if (x[4] <= 5.0100f) {  // pH <= 5.0100
                                        return 1; // Bawang Merah
                                    } else {  // pH > 5.0100
                                        if (x[6] <= 72.4803f) {  // Hum <= 72.4803
                                            return 0; // Bawang Daun
                                        } else {  // Hum > 72.4803
                                            return 1; // Bawang Merah
                                        }
                                    }
                                }
                            } else {  // Temp > 30.8302
                                return 0; // Bawang Daun
                            }
                        }
                    } else {  // Hum > 76.5410
                        if (x[6] <= 89.8470f) {  // Hum <= 89.8470
                            if (x[3] <= 142.3922f) {  // EC <= 142.3922
                                return 2; // Cabai
                            } else {  // EC > 142.3922
                                if (x[4] <= 5.0023f) {  // pH <= 5.0023
                                    return 2; // Cabai
                                } else {  // pH > 5.0023
                                    if (x[3] <= 157.7699f) {  // EC <= 157.7699
                                        return 0; // Bawang Daun
                                    } else {  // EC > 157.7699
                                        return 2; // Cabai
                                    }
                                }
                            }
                        } else {  // Hum > 89.8470
                            return 0; // Bawang Daun
                        }
                    }
                } else {  // P > 13.1928
                    if (x[2] <= 0.9000f) {  // K <= 0.9000
                        if (x[1] <= 14.9837f) {  // P <= 14.9837
                            return 1; // Bawang Merah
                        } else {  // P > 14.9837
                            if (x[0] <= 4.9657f) {  // N <= 4.9657
                                if (x[5] <= 26.3953f) {  // Temp <= 26.3953
                                    if (x[3] <= 36.0940f) {  // EC <= 36.0940
                                        return 3; // Parsley
                                    } else {  // EC > 36.0940
                                        if (x[6] <= 85.6410f) {  // Hum <= 85.6410
                                            return 3; // Parsley
                                        } else {  // Hum > 85.6410
                                            if (x[1] <= 15.0967f) {  // P <= 15.0967
                                                if (x[5] <= 24.4346f) {  // Temp <= 24.4346
                                                    return 3; // Parsley
                                                } else {  // Temp > 24.4346
                                                    return 3; // Parsley
                                                }
                                            } else {  // P > 15.0967
                                                return 3; // Parsley
                                            }
                                        }
                                    }
                                } else {  // Temp > 26.3953
                                    return 1; // Bawang Merah
                                }
                            } else {  // N > 4.9657
                                return 1; // Bawang Merah
                            }
                        }
                    } else {  // K > 0.9000
                        if (x[5] <= 26.7578f) {  // Temp <= 26.7578
                            return 2; // Cabai
                        } else {  // Temp > 26.7578
                            if (x[2] <= 9.3351f) {  // K <= 9.3351
                                if (x[6] <= 81.7621f) {  // Hum <= 81.7621
                                    return 5; // Tomat
                                } else {  // Hum > 81.7621
                                    if (x[4] <= 4.8900f) {  // pH <= 4.8900
                                        if (x[5] <= 28.3118f) {  // Temp <= 28.3118
                                            return 5; // Tomat
                                        } else {  // Temp > 28.3118
                                            if (x[4] <= 4.5890f) {  // pH <= 4.5890
                                                return 5; // Tomat
                                            } else {  // pH > 4.5890
                                                return 1; // Bawang Merah
                                            }
                                        }
                                    } else {  // pH > 4.8900
                                        if (x[6] <= 86.1904f) {  // Hum <= 86.1904
                                            return 1; // Bawang Merah
                                        } else {  // Hum > 86.1904
                                            return 1; // Bawang Merah
                                        }
                                    }
                                }
                            } else {  // K > 9.3351
                                return 1; // Bawang Merah
                            }
                        }
                    }
                }
            }
        } else {  // EC > 201.4307
            if (x[6] <= 77.6314f) {  // Hum <= 77.6314
                if (x[1] <= 17.0725f) {  // P <= 17.0725
                    return 2; // Cabai
                } else {  // P > 17.0725
                    return 6; // Zucchini
                }
            } else {  // Hum > 77.6314
                if (x[2] <= 26.6539f) {  // K <= 26.6539
                    return 1; // Bawang Merah
                } else {  // K > 26.6539
                    if (x[4] <= 4.5306f) {  // pH <= 4.5306
                        return 6; // Zucchini
                    } else {  // pH > 4.5306
                        return 2; // Cabai
                    }
                }
            }
        }
    } else {  // Hum > 93.3893
        if (x[2] <= 3.4378f) {  // K <= 3.4378
            return 2; // Cabai
        } else {  // K > 3.4378
            if (x[5] <= 30.8133f) {  // Temp <= 30.8133
                if (x[6] <= 94.7435f) {  // Hum <= 94.7435
                    if (x[4] <= 5.3647f) {  // pH <= 5.3647
                        return 2; // Cabai
                    } else {  // pH > 5.3647
                        return 0; // Bawang Daun
                    }
                } else {  // Hum > 94.7435
                    if (x[0] <= 10.0081f) {  // N <= 10.0081
                        return 0; // Bawang Daun
                    } else {  // N > 10.0081
                        return 0; // Bawang Daun
                    }
                }
            } else {  // Temp > 30.8133
                return 0; // Bawang Daun
            }
        }
    }
} else {  // N > 42.3298
    return 4; // Selada 
}
}

// --- Tree 9 of 10 ---
static int tree_8(float *x) {
if (x[3] <= 77.9333f) {  // EC <= 77.9333
    if (x[3] <= 54.9365f) {  // EC <= 54.9365
        if (x[5] <= 26.6773f) {  // Temp <= 26.6773
            if (x[1] <= 15.0130f) {  // P <= 15.0130
                if (x[6] <= 90.7490f) {  // Hum <= 90.7490
                    if (x[3] <= 44.9508f) {  // EC <= 44.9508
                        if (x[3] <= 41.0062f) {  // EC <= 41.0062
                            return 3; // Parsley
                        } else {  // EC > 41.0062
                            return 3; // Parsley
                        }
                    } else {  // EC > 44.9508
                        if (x[2] <= 0.5771f) {  // K <= 0.5771
                            if (x[3] <= 48.5709f) {  // EC <= 48.5709
                                return 3; // Parsley
                            } else {  // EC > 48.5709
                                if (x[5] <= 24.8364f) {  // Temp <= 24.8364
                                    return 2; // Cabai
                                } else {  // Temp > 24.8364
                                    return 3; // Parsley
                                }
                            }
                        } else {  // K > 0.5771
                            return 2; // Cabai
                        }
                    }
                } else {  // Hum > 90.7490
                    return 3; // Parsley
                }
            } else {  // P > 15.0130
                return 3; // Parsley
            }
        } else {  // Temp > 26.6773
            return 1; // Bawang Merah
        }
    } else {  // EC > 54.9365
        if (x[0] <= 5.9096f) {  // N <= 5.9096
            return 1; // Bawang Merah
        } else {  // N > 5.9096
            return 5; // Tomat
        }
    }
} else {  // EC > 77.9333
    if (x[0] <= 33.8186f) {  // N <= 33.8186
        if (x[1] <= 13.8897f) {  // P <= 13.8897
            if (x[5] <= 30.2915f) {  // Temp <= 30.2915
                if (x[5] <= 27.5653f) {  // Temp <= 27.5653
                    if (x[5] <= 26.9733f) {  // Temp <= 26.9733
                        return 2; // Cabai
                    } else {  // Temp > 26.9733
                        if (x[6] <= 85.5426f) {  // Hum <= 85.5426
                            return 1; // Bawang Merah
                        } else {  // Hum > 85.5426
                            return 0; // Bawang Daun
                        }
                    }
                } else {  // Temp > 27.5653
                    if (x[4] <= 4.8974f) {  // pH <= 4.8974
                        return 1; // Bawang Merah
                    } else {  // pH > 4.8974
                        if (x[6] <= 76.2842f) {  // Hum <= 76.2842
                            if (x[2] <= 15.0395f) {  // K <= 15.0395
                                if (x[4] <= 5.9119f) {  // pH <= 5.9119
                                    return 0; // Bawang Daun
                                } else {  // pH > 5.9119
                                    return 0; // Bawang Daun
                                }
                            } else {  // K > 15.0395
                                return 1; // Bawang Merah
                            }
                        } else {  // Hum > 76.2842
                            return 0; // Bawang Daun
                        }
                    }
                }
            } else {  // Temp > 30.2915
                return 0; // Bawang Daun
            }
        } else {  // P > 13.8897
            if (x[5] <= 26.5428f) {  // Temp <= 26.5428
                if (x[0] <= 15.5259f) {  // N <= 15.5259
                    return 2; // Cabai
                } else {  // N > 15.5259
                    if (x[2] <= 26.7622f) {  // K <= 26.7622
                        return 2; // Cabai
                    } else {  // K > 26.7622
                        return 2; // Cabai
                    }
                }
            } else {  // Temp > 26.5428
                if (x[1] <= 23.3929f) {  // P <= 23.3929
                    if (x[3] <= 300.5252f) {  // EC <= 300.5252
                        if (x[3] <= 160.9834f) {  // EC <= 160.9834
                            if (x[6] <= 75.2116f) {  // Hum <= 75.2116
                                return 5; // Tomat
                            } else {  // Hum > 75.2116
                                if (x[5] <= 28.2945f) {  // Temp <= 28.2945
                                    return 5; // Tomat
                                } else {  // Temp > 28.2945
                                    if (x[2] <= 3.1335f) {  // K <= 3.1335
                                        return 1; // Bawang Merah
                                    } else {  // K > 3.1335
                                        return 5; // Tomat
                                    }
                                }
                            }
                        } else {  // EC > 160.9834
                            return 1; // Bawang Merah
                        }
                    } else {  // EC > 300.5252
                        return 6; // Zucchini
                    }
                } else {  // P > 23.3929
                    return 6; // Zucchini
                }
            }
        }
    } else {  // N > 33.8186
        return 4; // Selada 
    }
}
}

// --- Tree 10 of 10 ---
static int tree_9(float *x) {
if (x[3] <= 310.5236f) {  // EC <= 310.5236
    if (x[0] <= 16.0445f) {  // N <= 16.0445
        if (x[3] <= 131.7135f) {  // EC <= 131.7135
            if (x[1] <= 13.2355f) {  // P <= 13.2355
                if (x[4] <= 5.1326f) {  // pH <= 5.1326
                    return 2; // Cabai
                } else {  // pH > 5.1326
                    if (x[2] <= 8.7706f) {  // K <= 8.7706
                        return 0; // Bawang Daun
                    } else {  // K > 8.7706
                        if (x[5] <= 27.1980f) {  // Temp <= 27.1980
                            return 2; // Cabai
                        } else {  // Temp > 27.1980
                            return 0; // Bawang Daun
                        }
                    }
                }
            } else {  // P > 13.2355
                if (x[2] <= 3.3378f) {  // K <= 3.3378
                    if (x[1] <= 14.2056f) {  // P <= 14.2056
                        if (x[2] <= 2.2656f) {  // K <= 2.2656
                            if (x[6] <= 93.8611f) {  // Hum <= 93.8611
                                if (x[6] <= 81.4775f) {  // Hum <= 81.4775
                                    if (x[0] <= 6.2171f) {  // N <= 6.2171
                                        if (x[4] <= 5.5044f) {  // pH <= 5.5044
                                            return 1; // Bawang Merah
                                        } else {  // pH > 5.5044
                                            return 5; // Tomat
                                        }
                                    } else {  // N > 6.2171
                                        if (x[2] <= 1.5920f) {  // K <= 1.5920
                                            return 5; // Tomat
                                        } else {  // K > 1.5920
                                            if (x[3] <= 89.8414f) {  // EC <= 89.8414
                                                if (x[4] <= 5.7679f) {  // pH <= 5.7679
                                                    if (x[6] <= 68.1526f) {  // Hum <= 68.1526
                                                        return 5; // Tomat
                                                    } else {  // Hum > 68.1526
                                                        if (x[3] <= 84.7914f) {  // EC <= 84.7914
                                                            return 1; // Bawang Merah
                                                        } else {  // EC > 84.7914
                                                            if (x[6] <= 75.7270f) {  // Hum <= 75.7270
                                                                return 5; // Tomat
                                                            } else {  // Hum > 75.7270
                                                                return 1; // Bawang Merah
                                                            }
                                                        }
                                                    }
                                                } else {  // pH > 5.7679
                                                    return 5; // Tomat
                                                }
                                            } else {  // EC > 89.8414
                                                return 5; // Tomat
                                            }
                                        }
                                    }
                                } else {  // Hum > 81.4775
                                    if (x[5] <= 28.3760f) {  // Temp <= 28.3760
                                        if (x[3] <= 87.0037f) {  // EC <= 87.0037
                                            if (x[0] <= 6.7447f) {  // N <= 6.7447
                                                return 5; // Tomat
                                            } else {  // N > 6.7447
                                                if (x[2] <= 1.0397f) {  // K <= 1.0397
                                                    return 5; // Tomat
                                                } else {  // K > 1.0397
                                                    return 5; // Tomat
                                                }
                                            }
                                        } else {  // EC > 87.0037
                                            return 5; // Tomat
                                        }
                                    } else {  // Temp > 28.3760
                                        return 1; // Bawang Merah
                                    }
                                }
                            } else {  // Hum > 93.8611
                                return 2; // Cabai
                            }
                        } else {  // K > 2.2656
                            return 2; // Cabai
                        }
                    } else {  // P > 14.2056
                        if (x[6] <= 86.6963f) {  // Hum <= 86.6963
                            if (x[2] <= 0.0591f) {  // K <= 0.0591
                                if (x[5] <= 25.8271f) {  // Temp <= 25.8271
                                    if (x[4] <= 5.3281f) {  // pH <= 5.3281
                                        if (x[4] <= 4.9726f) {  // pH <= 4.9726
                                            if (x[4] <= 4.5819f) {  // pH <= 4.5819
                                                return 2; // Cabai
                                            } else {  // pH > 4.5819
                                                return 3; // Parsley
                                            }
                                        } else {  // pH > 4.9726
                                            return 3; // Parsley
                                        }
                                    } else {  // pH > 5.3281
                                        return 3; // Parsley
                                    }
                                } else {  // Temp > 25.8271
                                    if (x[5] <= 27.3592f) {  // Temp <= 27.3592
                                        return 3; // Parsley
                                    } else {  // Temp > 27.3592
                                        return 1; // Bawang Merah
                                    }
                                }
                            } else {  // K > 0.0591
                                return 2; // Cabai
                            }
                        } else {  // Hum > 86.6963
                            if (x[1] <= 15.1213f) {  // P <= 15.1213
                                return 3; // Parsley
                            } else {  // P > 15.1213
                                if (x[4] <= 5.0893f) {  // pH <= 5.0893
                                    return 3; // Parsley
                                } else {  // pH > 5.0893
                                    return 3; // Parsley
                                }
                            }
                        }
                    }
                } else {  // K > 3.3378
                    return 5; // Tomat
                }
            }
        } else {  // EC > 131.7135
            if (x[0] <= 15.4201f) {  // N <= 15.4201
                if (x[0] <= 11.9862f) {  // N <= 11.9862
                    if (x[4] <= 4.7037f) {  // pH <= 4.7037
                        return 2; // Cabai
                    } else {  // pH > 4.7037
                        return 0; // Bawang Daun
                    }
                } else {  // N > 11.9862
                    if (x[2] <= 13.0117f) {  // K <= 13.0117
                        return 0; // Bawang Daun
                    } else {  // K > 13.0117
                        if (x[3] <= 168.2525f) {  // EC <= 168.2525
                            if (x[2] <= 14.5172f) {  // K <= 14.5172
                                return 0; // Bawang Daun
                            } else {  // K > 14.5172
                                if (x[5] <= 31.3313f) {  // Temp <= 31.3313
                                    if (x[4] <= 4.9953f) {  // pH <= 4.9953
                                        return 0; // Bawang Daun
                                    } else {  // pH > 4.9953
                                        if (x[5] <= 27.8950f) {  // Temp <= 27.8950
                                            return 2; // Cabai
                                        } else {  // Temp > 27.8950
                                            if (x[6] <= 88.6416f) {  // Hum <= 88.6416
                                                if (x[3] <= 166.3481f) {  // EC <= 166.3481
                                                    if (x[3] <= 163.1708f) {  // EC <= 163.1708
                                                        return 0; // Bawang Daun
                                                    } else {  // EC > 163.1708
                                                        return 0; // Bawang Daun
                                                    }
                                                } else {  // EC > 166.3481
                                                    return 0; // Bawang Daun
                                                }
                                            } else {  // Hum > 88.6416
                                                return 0; // Bawang Daun
                                            }
                                        }
                                    }
                                } else {  // Temp > 31.3313
                                    return 0; // Bawang Daun
                                }
                            }
                        } else {  // EC > 168.2525
                            return 1; // Bawang Merah
                        }
                    }
                }
            } else {  // N > 15.4201
                return 1; // Bawang Merah
            }
        }
    } else {  // N > 16.0445
        if (x[4] <= 5.6278f) {  // pH <= 5.6278
            if (x[4] <= 4.3398f) {  // pH <= 4.3398
                return 1; // Bawang Merah
            } else {  // pH > 4.3398
                if (x[3] <= 218.8460f) {  // EC <= 218.8460
                    return 1; // Bawang Merah
                } else {  // EC > 218.8460
                    return 2; // Cabai
                }
            }
        } else {  // pH > 5.6278
            return 2; // Cabai
        }
    }
} else {  // EC > 310.5236
    if (x[5] <= 31.1356f) {  // Temp <= 31.1356
        return 6; // Zucchini
    } else {  // Temp > 31.1356
        if (x[1] <= 47.3086f) {  // P <= 47.3086
            return 6; // Zucchini
        } else {  // P > 47.3086
            return 4; // Selada 
        }
    }
}
}

// ============================================================
// predict() — majority voting dari semua pohon
// Input  : float x[]  → nilai sensor sesuai urutan features
// Output : int        → indeks kelas prediksi
//          0=Bawang Daun, 1=Bawang Merah, 2=Cabai, 3=Parsley, 4=Selada , 5=Tomat, 6=Zucchini
// ============================================================
int predict(float *x) {
    int votes[7] = {0};

    votes[tree_0(x)]++;
    votes[tree_1(x)]++;
    votes[tree_2(x)]++;
    votes[tree_3(x)]++;
    votes[tree_4(x)]++;
    votes[tree_5(x)]++;
    votes[tree_6(x)]++;
    votes[tree_7(x)]++;
    votes[tree_8(x)]++;
    votes[tree_9(x)]++;

    int best = 0;
    for (int i = 1; i < 7; i++) {
        if (votes[i] > votes[best]) best = i;
    }
    return best;
}

// ============================================================
// predict_proba() — persentase keyakinan tiap kelas (0.0–1.0)
// Input  : float x[]      → nilai sensor
//          float proba[]  → array output ukuran N_CLASSES
// Output : proba[i] = 0.0–1.0, kalikan 100 untuk persen
//          0=Bawang Daun, 1=Bawang Merah, 2=Cabai, 3=Parsley, 4=Selada , 5=Tomat, 6=Zucchini
// ============================================================
void predict_proba(float *x, float *proba) {
    int votes[7] = {0};

    votes[tree_0(x)]++;
    votes[tree_1(x)]++;
    votes[tree_2(x)]++;
    votes[tree_3(x)]++;
    votes[tree_4(x)]++;
    votes[tree_5(x)]++;
    votes[tree_6(x)]++;
    votes[tree_7(x)]++;
    votes[tree_8(x)]++;
    votes[tree_9(x)]++;

    for (int i = 0; i < 7; i++) {
        proba[i] = (float)votes[i] / (float)10;
    }
}
