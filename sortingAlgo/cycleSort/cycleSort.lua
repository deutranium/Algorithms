local function cycleSort(t)
    local n = #t
    for i = 1, n do
        local item = t[i]
        local pos = i
        for j = i + 1, n do
            if t[j] < item then
                pos = pos + 1
            end
        end
        if pos == i then
            goto continue
        end
        while item == t[pos] do
            pos = pos + 1
        end
        t[pos], item = item, t[pos]
        ::continue::
        while pos ~= i do
            pos = i
            for j = i + 1, n do
                if t[j] < item then
                    pos = pos + 1
                end
            end
            while item == t[pos] do
                pos = pos + 1
            end
            t[pos], item = item, t[pos]
        end
    end
end

local t = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 }
cycleSort(t)
print(table.concat(t, ", "))