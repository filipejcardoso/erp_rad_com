object FListaUnidadesMedidasView: TFListaUnidadesMedidasView
  Left = 0
  Top = 0
  Caption = 'CRUD - UnidadesMedidas'
  ClientHeight = 960
  ClientWidth = 1109
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object PanelSearch: TPanel
    Left = 0
    Top = 97
    Width = 1109
    Height = 81
    Align = alTop
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = 18
    Font.Name = 'Calibri'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
    object BtSearch: TSpeedButton
      Left = 732
      Top = 30
      Width = 152
      Height = 30
      Caption = 'BUSCAR'
      Glyph.Data = {
        F6060000424DF606000000000000360000002800000018000000180000000100
        180000000000C0060000120B0000120B00000000000000000000C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0B9B9B9B0B0B0AFAF
        AFB6B6B6BEBEBEC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BEBEBE
        86898B5E72815A7385707A80B5B5B5C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0BEBEBE8D8D8E467DA630A7FB35B9FF46AAE78D9295C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0BEBEBE8C8C8D447BA32BA1F424A8FF64CCFF50C0FD848A90C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0BEBEBE8B8D8F477FA825A2FA1EA5FF7FCDFFBFF6
        FF50BAEE91969AC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BBBBBBAC
        ACACA7A7A7A8A8A8A7A7A7ACACACBCBCBCBFBFBF8E8B8A507B9B23A3FC19A4FF
        7ECDFFC9FCFF5DB3D77EA7C1BBBBBCC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BEBE
        BEA4A4A48281807271716E6E6E6F6E6F6F6E6F727171868686848484847A7398
        A6B13EA5E773CDFEC5FAFF60BCDC718693C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0BBBBBB8F8E8E767474A2A2A5CDCFD4DBDDE1DCDDE2DCDDE1CECED49999
        9C7A7878969491B8ABA1CBD0D1D6FEFF5FBBDA728C9DC0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0BFBFBF8C8C8C8A8887D0D2D6F0EEEEF0DECAF4DBBBF4DCBB
        F4DCBAF1DFC9F0EDEBCACDD38A8989ABA9A9FFFFF3B1C1C7778D9CC0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C09E9E9E868584DEE1E4F1EAE0EFCB99F3
        C37BF4C474F7CA79F9CE7DF9CE84F2CE9CF1E7DDC4C7CCA5A4A4AEACAA9C938F
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0B9B9B97B7A7ACECFD1F2EE
        E8EABE82ECB665EAC57DEDD18DF1DA97F5E19DF9E49AFAD381EFC58AF1E9E1CE
        D0D4747372BBBBBBC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C09E9E9E
        9B9A9AEEEEEEEACCA6E5AF62E8C385ECCB89F1D38EF6DD97FAE7A0FCF0AAFDEE
        A7F3CB7BEFD2AAEDEBED9595959C9C9CC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C08A8A8AC1C1C1F1ECE6DFAD6BE8C088EFD5A7EFD094F2D48FF5DD95
        FAE8A2FEEFA8FDEEA7F7DE93E5BE7EF3E9DFC6C8CB888887C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0888888CCCCCCF5EDE5D79E55EECFA5F2DEBAF0
        D5A3F2D79AF4DA95F7E09AF9E5A0F8E49EF8E098DFB46EF7EAD9CDD1D4868686
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0898989CFCFD0F7EFE5CF96
        4DF2D7B4F5E4CAF2D8AEF2D9A7F3D99BF4D994F4DA94F3DA95F6D992D9AD68F7
        E8D6D1D2D4868686C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C08A8A89
        CECECFF6F0E8CA944FF2D6B3F8EDDBF2DBB9F2DBB1F2D9A6F1D599F0D18DF0D0
        8BF1CE86D3A867F5EADAD2D2D4888887C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C09D9D9DBBBAB9FAF8F7CEA978DCAF77FFFAF1F5EAD4F1DCB8F2D8AD
        F0D5A2EDCE93F3D08CDFB065D4B384F7F4F0C2C2C4999898C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0B9B9B9908F8EF3F5F6EADCCABC8A4AEBC89FFF
        F4E4F9F0E0F7E6CEF4DEBCF6D7A3E4B66FC29352EADBC9F5F6F9969595B2B2B2
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0A09F9FB9B9B8FFFF
        FFE0CEB8B98747D1A165E9BF8EEAC28AE8BC81D3A25FBA8E50DECBB4FFFFFFC1
        C0C1979797BFBFBFC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        BEBEBE979696C2C1C0FFFFFFF1E9DECDB089BB8F58B98E54BB925ACEB18CF1E8
        DDFFFFFFC8C7C7959494BDBDBDC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0BCBCBCA6A5A4ABAAA9E3E4E4FAF9F8FAF7F3FAF7F3
        FAF7F4F9F8F7E4E4E4AFADACA3A2A2BDBDBDC0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0BFBFBFABABAB9C9C9BAB
        ABA9AAAAA8AAA9A7AAA9A7AEACAB9C9B9AB0B0AFBFBFBFC0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
      OnClick = BtSearchClick
    end
    object BtInsert: TSpeedButton
      Left = 893
      Top = 30
      Width = 189
      Height = 30
      Caption = 'NOVO RECURSO'
      Glyph.Data = {
        F6060000424DF606000000000000360000002800000018000000180000000100
        180000000000C0060000120B0000120B00000000000000000000C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0B2B4B26E776F464F47
        444D45454F45454F45454F45414D41575E57A4A4A4C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C08C
        A18C33823645A54D43A24A42A04941A04945A64C35933B274627A0A0A0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C091A091549B5A3DC4491EAF291FA6281DA4252BB43356B85F2C
        472CA0A0A0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C091A19150975422B22E009D09009407008C
        040D97114AAC522C492DA0A0A0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C091A49150975528B635
        08A71309A01305960E109B194CAC542C492DA1A1A1C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C094
        9D9450955528B83407A71309A414069E1010A11A4CAC532E4A2FA5A5A5C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0A4A4A49F9F9FA0A0
        A0A0A0A0AAAAAA7D7D7D4C8E5128BB3407A81309A61507A41212A81C4BAC532B
        432B8B8B8BA4A4A4A1A1A1A0A0A0A0A0A0A0A0A0A5A5A5C0C0C0C0C0C0566B56
        2F482F2C452C2C462C2C472C324C33233A23478C4B2ABA3607A81309A71506A6
        1313AD1F50AD58113D112B452B2E4A2F2D492E2C492E2C472C2A482A585F58C0
        C0C0C0C0C01F72245EB96658B25F57B25F4FAF5849AD514AAA5161BC6922B12D
        06A61209A71507A6130FAA1B57BF6151AD574BAC534CAC534CAC544AAB5357B6
        5E35933B3F4B3FC0C0C0C0C0C02C7E3083DE8B76D27D71D27A59C96327B7330F
        AE1B0FAB1B0BA81709A71509A71509A71508A7140EAA1B13AD1F12A91C11A31B
        109C190F97112AB23245A64D454E45C0C0C0C0C0C02C7C3283D98A78CE7D72CD
        796DCC7558C46127B13205A51104A61009A71509A71509A71509A71507A61306
        A61307A512059F1104980F008D031CA52542A049454F45C0C0C0C0C0C02D7C31
        87DB8D7FD08578CF7E74CD7B72CD7968C96E3FBB4714AB1F06A61208A71408A7
        1409A71509A71509A71509A71509A51509A2140096091FA82842A049454F45C0
        C0C0C0C0C02C7C318EE0968BD69183D4897FD28578D17E74CF7B6ECD7556C25E
        2CB4370FA91A07A61307A61305A61207A81307A81307A81308A814009E0A1EAF
        2943A24A454E45C0C0C0C0C0C026792C8FE1988CD99386D88D83D58A7FD58579
        D48175D07D70CC7769C9704DBF5529B23412AB1D22B12E2ABA3528B93428B634
        29B73522B22D3DC44946A44D444E44C0C0C0C0C0C02A712D4D975349934E4A93
        4E4A934F4C9451458A4959AD6174D07D71CE786ECB7464C76A52C45A66BF6F45
        8B4A4D9051519655509654509654549C593583396C756DC0C0C0C0C0C094A594
        91A09191A09191A09191A09194A2946F836F438B467DD48477D17E6FCC766BCB
        7270D17755AE5C2435247C847C92A49291A19191A09191A0918FA28FB2B4B3C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C09BA79B4D945183D68A
        7FD38676CE7D71CD7871D17857B25F324632AEAFAEC0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C090
        9F904A934E87D88F86D68D7ED18479CF7F77D48057B35F2C462CA0A0A0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C091A09149934E8CDA938DD99485D38B80D2857FD68558B3612C
        462CA0A0A0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C091A09149934D94DC9B99DB9D8FD69489D4
        8F87D98C5AB3612C452CA0A0A0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0909F904D985193E39C
        96E29C8FDE968CDD938EE39560BA682F482FA4A4A4C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C093
        A4932F7333287A2F2C7B312C7B302C7B302C7E31237528546954BEBEBEC0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
      OnClick = BtInsertClick
    end
    object Label3: TLabel
      Left = 437
      Top = 12
      Width = 45
      Height = 18
      Caption = 'P'#225'gina:'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object Label5: TLabel
      Left = 24
      Top = 10
      Width = 100
      Height = 18
      Caption = 'Campo de Busca'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object Label4: TLabel
      Left = 589
      Top = 12
      Width = 131
      Height = 18
      Caption = 'N'#250'mero de registros:'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object ComboPage: TComboBox
      Left = 437
      Top = 36
      Width = 131
      Height = 22
      Style = csOwnerDrawFixed
      ItemIndex = 0
      TabOrder = 0
      Text = '1'
      Items.Strings = (
        '1'
        '2'
        '3'
        '4'
        '5'
        '6'
        '7')
    end
    object EditBusca: TEdit
      Left = 24
      Top = 32
      Width = 393
      Height = 26
      TabOrder = 1
      OnKeyPress = EditFilterValueKeyPress
    end
    object ComboPerPage: TComboBox
      Left = 589
      Top = 36
      Width = 131
      Height = 22
      Style = csOwnerDrawFixed
      ItemIndex = 0
      TabOrder = 2
      Text = 'NOME'
      Items.Strings = (
        'NOME'
        'CODIGO DE BARRAS'
        'MARCA')
    end
    object CheckFilterAdvanced: TCheckBox
      Left = 1088
      Top = 38
      Width = 150
      Height = 17
      Caption = 'Filtragem Avan'#231'ada'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 15790835
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 3
      OnClick = CheckFilterAdvancedClick
    end
  end
  object PanelOptions: TPanel
    Left = 0
    Top = 178
    Width = 361
    Height = 782
    Align = alLeft
    TabOrder = 1
    object ScrollBox1: TScrollBox
      Left = 1
      Top = 1
      Width = 359
      Height = 780
      VertScrollBar.ParentColor = False
      VertScrollBar.Range = 850
      VertScrollBar.Style = ssFlat
      Align = alClient
      AutoScroll = False
      TabOrder = 0
      object PanelFiltersOptions: TPanel
        Left = 0
        Top = 250
        Width = 338
        Height = 300
        Align = alTop
        TabOrder = 0
        object StringGridFilters: TStringGrid
          Left = 1
          Top = 145
          Width = 336
          Height = 154
          Align = alClient
          TabOrder = 0
          OnDrawCell = StringGridFiltersDrawCell
          OnMouseDown = StringGridFiltersMouseDown
          OnSelectCell = StringGridFiltersSelectCell
          ColWidths = (
            64
            64
            64
            64
            64)
          RowHeights = (
            24
            24
            24
            24
            24)
        end
        object PanelFiltersComponents: TPanel
          Left = 1
          Top = 1
          Width = 336
          Height = 144
          Align = alTop
          ParentBackground = False
          TabOrder = 1
          object Label1: TLabel
            Left = 27
            Top = 4
            Width = 39
            Height = 18
            Caption = 'Value:'
            Color = 15790835
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentColor = False
            ParentFont = False
          end
          object Label6: TLabel
            Left = 27
            Top = 52
            Width = 63
            Height = 18
            Caption = 'Operador:'
            Color = 15790835
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentColor = False
            ParentFont = False
          end
          object Label2: TLabel
            Left = 185
            Top = 52
            Width = 65
            Height = 18
            Caption = 'Filtrar por:'
            Color = 15790835
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentColor = False
            ParentFont = False
          end
          object Label9: TLabel
            Left = 104
            Top = 52
            Width = 42
            Height = 18
            Caption = 'L'#243'gica:'
            Color = 15790835
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentColor = False
            ParentFont = False
          end
          object EditFilterValue: TEdit
            Left = 27
            Top = 25
            Width = 303
            Height = 26
            TabOrder = 0
            OnKeyPress = EditFilterValueKeyPress
          end
          object ComboOperator: TComboBox
            Left = 27
            Top = 71
            Width = 66
            Height = 22
            Style = csOwnerDrawFixed
            ItemIndex = 0
            TabOrder = 1
            Text = 'like'
            Items.Strings = (
              'like'
              '='
              '>'
              '<'
              '<>')
          end
          object ComboField: TComboBox
            Left = 185
            Top = 71
            Width = 145
            Height = 22
            Style = csOwnerDrawFixed
            ItemIndex = 0
            TabOrder = 2
            Text = 'NOME'
            Items.Strings = (
              'NOME'
              'CODIGO DE BARRAS'
              'MARCA')
          end
          object ButtonFiltro: TButton
            Left = 27
            Top = 107
            Width = 139
            Height = 25
            Caption = 'ADICIONAR'
            TabOrder = 3
            OnClick = ButtonFiltroClick
          end
          object Button1: TButton
            Left = 185
            Top = 107
            Width = 145
            Height = 25
            Caption = 'REMOVER'
            TabOrder = 4
            OnClick = Button1Click
          end
          object ComboLogic: TComboBox
            Left = 104
            Top = 71
            Width = 62
            Height = 22
            Style = csOwnerDrawFixed
            ItemIndex = 0
            TabOrder = 5
            Text = 'like'
            Items.Strings = (
              'like'
              '='
              '>'
              '<'
              '<>')
          end
        end
      end
      object PanelSortOptions: TPanel
        Left = 0
        Top = 550
        Width = 338
        Height = 300
        Align = alTop
        TabOrder = 1
        object StringGridSort: TStringGrid
          Left = 1
          Top = 105
          Width = 336
          Height = 194
          Align = alClient
          TabOrder = 0
          OnDrawCell = StringGridSortDrawCell
          OnMouseDown = StringGridSortMouseDown
          OnSelectCell = StringGridSortSelectCell
          ColWidths = (
            64
            64
            64
            64
            64)
          RowHeights = (
            24
            24
            24
            24
            24)
        end
        object PanelSortComponents: TPanel
          Left = 1
          Top = 1
          Width = 336
          Height = 104
          Align = alTop
          ParentBackground = False
          TabOrder = 1
          object Label7: TLabel
            Left = 22
            Top = 7
            Width = 79
            Height = 18
            Caption = 'Ordenar por:'
            Color = 15790835
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentColor = False
            ParentFont = False
          end
          object Label8: TLabel
            Left = 185
            Top = 7
            Width = 71
            Height = 18
            Caption = 'Ordena'#231#227'o:'
            Color = 15790835
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = 18
            Font.Name = 'Calibri'
            Font.Style = []
            ParentColor = False
            ParentFont = False
          end
          object ComboSortField: TComboBox
            Left = 22
            Top = 26
            Width = 145
            Height = 22
            Style = csOwnerDrawFixed
            ItemIndex = 0
            TabOrder = 0
            Text = 'NOME'
            Items.Strings = (
              'NOME'
              'CODIGO DE BARRAS'
              'MARCA')
          end
          object ComboSortOrder: TComboBox
            Left = 185
            Top = 26
            Width = 145
            Height = 22
            Style = csOwnerDrawFixed
            ItemIndex = 0
            TabOrder = 1
            Text = 'ASC'
            Items.Strings = (
              'ASC'
              'DESC')
          end
          object Button2: TButton
            Left = 19
            Top = 61
            Width = 148
            Height = 26
            Caption = 'ADICIONAR'
            TabOrder = 2
            OnClick = Button2Click
          end
          object Button3: TButton
            Left = 185
            Top = 61
            Width = 145
            Height = 26
            Caption = 'REMOVER'
            TabOrder = 3
            OnClick = Button3Click
          end
        end
      end
      object StringGridFields: TStringGrid
        Left = 0
        Top = 0
        Width = 338
        Height = 250
        Align = alTop
        TabOrder = 2
        OnDrawCell = StringGridFieldsDrawCell
        OnMouseDown = StringGridFieldsMouseDown
        OnSelectCell = StringGridFieldsSelectCell
        ColWidths = (
          64
          64
          64
          64
          64)
        RowHeights = (
          24
          24
          24
          24
          24)
      end
    end
  end
  object PanelTitle: TPanel
    Left = 0
    Top = 0
    Width = 1109
    Height = 97
    Align = alTop
    Color = 5395281
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGradientInactiveCaption
    Font.Height = 18
    Font.Name = 'Calibri'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 2
    object LabelCabecalhoTitulo: TLabel
      Left = 40
      Top = 15
      Width = 631
      Height = 40
      Caption = '[CLIENTES] Sistema de Gest'#227'o ERP MIPVendas'
      Color = clRed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 3198613
      Font.Height = 40
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object LabelCabecalhoSubTitulo: TLabel
      Left = 40
      Top = 61
      Width = 298
      Height = 20
      Caption = 'ELETROBIDU COMERCIAL EL'#201'TRICA LTDA-ME'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 15790835
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
  end
  object PanelMarca: TPanel
    Left = 361
    Top = 178
    Width = 748
    Height = 782
    Align = alClient
    TabOrder = 3
    object StringGrid1: TStringGrid
      Left = 1
      Top = 1
      Width = 746
      Height = 780
      Align = alClient
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
      TabOrder = 0
      OnDblClick = StringGrid1DblClick
      OnDrawCell = StringGrid1DrawCell
      OnMouseDown = StringGrid1MouseDown
      OnSelectCell = StringGrid1SelectCell
      ColWidths = (
        64
        64
        64
        64
        64)
      RowHeights = (
        24
        24
        24
        24
        24)
    end
  end
  object SQLQuery1: TSQLQuery
    Params = <>
    Left = 607
    Top = 271
  end
end
